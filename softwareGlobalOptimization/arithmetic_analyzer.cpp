#include "arithmetic_analyzer.h"

Lexem arithmetic_analyzer::number_analysis(int& current_char) {
    State state = q0;
    string number = "";
    size_t size = input_string.length();
    char c;

    while (true) {
        c = input_string[current_char];
        if (state == q0) {
            if ((c >= '0') && (c <= '9')) {
                number += c;
            }
            else if (c == '.') {
                number += c;
                state = q1;
            }
            else {
                current_char--;
                return Lexem(number, TypeElem::VALUE, atof(number.c_str()));
            }
        }
        if (state == q1) {
            if ((c >= '0') && (c <= '9')) {
                number += c;
            }
            else {
                current_char--;
                return Lexem(number, TypeElem::VALUE, atof(number.c_str()));
            }
        }
        current_char++;
    }
}

Lexem arithmetic_analyzer::minus_analysis() {
    if (qLexic->empty()) {
        return Lexem(string(1, '-'), TypeElem::UNARYOP, -1, -1);
    }
    else {
        Lexem l = qLexic->front();
        if (l.type == TypeElem::LP || l.type == TypeElem::BINARYOP || l.type == TypeElem::UNARYOP) {
            return Lexem(string(1, '-'), TypeElem::UNARYOP, -1, -1);
        }
        else {
            return Lexem(string(1, '-'), TypeElem::BINARYOP, -1, 1);
        }
    }
}

bool arithmetic_analyzer::sin_analysis(int& current_char, Lexem& l) {
    size_t size = input_string.length();
    if (current_char < size - 2) {
        if (input_string[current_char + 1] == 'i' && input_string[current_char + 2] == 'n') {
            current_char += 2;
            l.symbol = "sin";
            l.type = TypeElem::UNARYOP;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool arithmetic_analyzer::cos_analysis(int& current_char, Lexem& l) {
    int size = input_string.length();
    if (current_char < size - 2) {
        if (input_string[current_char + 1] == 'o' && input_string[current_char + 2] == 's') {
            current_char += 2;
            l.symbol = "cos";
            l.type = TypeElem::UNARYOP;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool arithmetic_analyzer::pi_analysis(int& current_char, Lexem& l) {
    int size = input_string.length();
    if (current_char < size - 1) {
        if (input_string[current_char + 1] == 'i') {
            current_char += 1;
            l.symbol = "pi";
            l.type = TypeElem::MATH_CONST;
            l.value = M_PI;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void arithmetic_analyzer::lexical_analysis() {
    Lexem l;
    int size = input_string.length();
    char c;
    int current_char = 0;

    for (int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == ' ') {
            input_string.erase(i);
        }
    }
    input_string += " ";

    while (true) {
        c = input_string[current_char];
        if ((c >= '0') && (c <= '9')) {
            qLexic->push(number_analysis(current_char));
        }
        else if ((c >= 'a') && (c <= 'z')) {
            if (c == 'c') {
                if (cos_analysis(current_char, l)) {
                    qLexic->push(l);
                }
                else {
                    qLexic->push(Lexem(string(1, c), TypeElem::VAR));
                }
            }
            else if (c == 'e') {
                qLexic->push(Lexem(string(1, c), TypeElem::MATH_CONST, exp(1.0)));
            }
            else if (c == 'p') {
                if (pi_analysis(current_char, l)) {
                    qLexic->push(l);
                }
                else {
                    qLexic->push(Lexem(string(1, c), TypeElem::VAR));
                }
            }
            else if (c == 's') {
                if (sin_analysis(current_char, l)) {
                    qLexic->push(l);
                }
                else {
                    qLexic->push(Lexem(string(1, c), TypeElem::VAR));
                }
            }
            else {
                qLexic->push(Lexem(string(1, c), TypeElem::VAR));
            }
        }
        else if (c == '-') {
            qLexic->push(minus_analysis());
        }
        else if (c == '+') {
            qLexic->push(Lexem(string(1, c), TypeElem::BINARYOP, -1, 1));
        }
        else if (c == '*' || c == '/') {
            qLexic->push(Lexem(string(1, c), TypeElem::BINARYOP, -1, 2));
        }
        else if (c == '^') {
            qLexic->push(Lexem(string(1, c), TypeElem::BINARYOP, -1, 3));
        }
        else if (c == '(') {
            qLexic->push(Lexem(string(1, c), TypeElem::LP));
        }
        else if (c == ')') {
            qLexic->push(Lexem(string(1, c), TypeElem::RP));
        }
        else if (c == ' ') {
            break;
        }
        else {
            throw logic_error("Arithmetic expression is invalid(Unknown characters)");
        }
        current_char++;
    }
}

void arithmetic_analyzer::syntactic_analysis() {
    State state = q0;
    int k = 0;
    bool unary_minus = false;
    queue<Lexem>* qLexic_tmp = new queue<Lexem>(*qLexic);
    Lexem l;

    while (!qLexic_tmp->empty()) {
        l = qLexic_tmp->front(); qLexic_tmp->pop();
        if (state == q0) {
            if (l.type == TypeElem::LP) {
                k++;
                // state = q0;
            }
            else if (l.type == TypeElem::UNARYOP) {
                if (l.symbol == "-") unary_minus = true;
                state = q2;
            }
            else if (l.type == TypeElem::VALUE || l.type == TypeElem::VAR || l.type == TypeElem::MATH_CONST) {
                state = q1;
            }
            else if (l.type == TypeElem::RP) {
                throw logic_error("Arithmetic expression is invalid(Incorrect parentheses)");
            }
            else if (l.type == TypeElem::BINARYOP) {
                throw logic_error("Arithmetic expression is invalid(The binary operation is in the wrong place)");
            }
            qSyntax->push(l);
        }
        else if (state == q1) {
            if (l.type == TypeElem::LP) {
                k++;
                qSyntax->push(Lexem(string(1, '*'), TypeElem::BINARYOP, -1, 2));
                state = q0;
            }
            else if (l.type == TypeElem::RP) {
                k--;
                if (k < 0)  throw logic_error("Arithmetic expression is invalid(Incorrect parentheses)");
                // state = q1;
            }
            else if (l.type == TypeElem::BINARYOP) {
                state = q2;
            }
            else if (l.type == TypeElem::UNARYOP) {
                // Унарный минус не может быть, т. к. такой случай отсекается на этапе лексического анализа
                qSyntax->push(Lexem(string(1, '*'), TypeElem::BINARYOP, -1, 2));
                state = q2;
            }
            else if (l.type == TypeElem::VAR || l.type == TypeElem::MATH_CONST || l.type == TypeElem::VALUE) {
                // VALUE только после TypeElem::RP, иные случаи отсекаются на этапе лексического анализа
                qSyntax->push(Lexem(string(1, '*'), TypeElem::BINARYOP, -1, 2));
                // state = q1;
            }
            qSyntax->push(l);
        }
        else if (state == q2) {
            if (l.type == TypeElem::LP) {
                k++;
                state = q0;
            }
            else if (l.type == TypeElem::UNARYOP) {
                // state = q2;
            }
            else if (l.type == TypeElem::VALUE || l.type == TypeElem::VAR || l.type == TypeElem::MATH_CONST) {
                if (l.type == TypeElem::VALUE && unary_minus) {
                    l.value = -l.value;
                    l.symbol = to_string(l.value);
                    unary_minus = false;
                    qSyntax->pop();
                }
                state = q1;
            }
            else if ((l.type == TypeElem::RP)) {
                throw logic_error("Arithmetic expression is invalid(Incorrect parentheses)");
            }
            else if ((l.type == TypeElem::BINARYOP)) {
                throw logic_error("Arithmetic expression is invalid(The binary operation is in the wrong place)");
            }
            qSyntax->push(l);
        }
    }
    if ((l.type == TypeElem::LP)) {
        throw logic_error("Arithmetic expression is invalid(Incorrect parentheses)");
    }
    else if (l.type == TypeElem::UNARYOP) {
        throw logic_error("Arithmetic expression is invalid(The unary operation is in the wrong place)");
    }
    else if ((l.type == TypeElem::BINARYOP)) {
        throw logic_error("Arithmetic expression is invalid(The binary operation is in the wrong place)");
    }
    if (k != 0) throw logic_error("Arithmetic expression is invalid(Incorrect parentheses)");
}

arithmetic_analyzer::arithmetic_analyzer()
    : ready(false), input_string(""), output_string(""), qRevPolNot(new queue<Lexem>()),
    qLexic(new queue<Lexem>()), qSyntax(new queue<Lexem>()), vars(new map<string, double>) {}

arithmetic_analyzer::arithmetic_analyzer(const string& str)
    : ready(false), input_string(str), output_string(""), qRevPolNot(new queue<Lexem>()),
    qLexic(new queue<Lexem>()), qSyntax(new queue<Lexem>()), vars(new map<string, double>) {}

void arithmetic_analyzer::init(const string& str) {
    input_string = str;
    output_string = "";
    ready = false;
    vars->clear();
    while (!qRevPolNot->empty()) qRevPolNot->pop();
    while (!qLexic->empty()) qLexic->pop();
    while (!qSyntax->empty()) qSyntax->pop();
}

const string& arithmetic_analyzer::get_input_string() const {
    return input_string;
}

const string& arithmetic_analyzer::get_output_string() const {
    if (!ready) throw logic_error("The output formula is not ready");
    return output_string;
}

bool arithmetic_analyzer::isReady() const {
    return ready;
}

bool arithmetic_analyzer::isVars() const {
    return !vars->empty();
}

int arithmetic_analyzer::countVars() const {
    return vars->size();
}

bool arithmetic_analyzer::setVar(const string& name, double value) {
    if (vars->empty()) return false;
    map<string, double>::iterator iter = vars->find(name);
    if (iter == vars->end()) return false;
    iter->second = value;
    return true;
}

void arithmetic_analyzer::conversToRevPolNot() {
    if (input_string.length() == 0) throw logic_error("The length of the string is zero");
    if (ready) return;
    lexical_analysis();
    syntactic_analysis();

    State state = q0;
    Lexem l, l1;
    stack<Lexem>* s = new stack<Lexem>;
    queue<Lexem>* qSyntax_tmp = new queue<Lexem>(*qSyntax);

    while (!qSyntax_tmp->empty()) {
        l = qSyntax_tmp->front(); qSyntax_tmp->pop();
        if (l.type == TypeElem::LP || l.type == TypeElem::UNARYOP) {
            s->push(l);
        }
        else if (l.type == TypeElem::VALUE || l.type == TypeElem::VAR || l.type == TypeElem::MATH_CONST) {
            if (l.type == TypeElem::VAR) {
                (*vars)[l.symbol] = 0.0;
            }
            qRevPolNot->push(l);
            output_string += l.symbol;
            output_string += " ";
        }
        else if (l.type == TypeElem::RP) {
            while (!s->empty()) {
                l = s->top();
                s->pop();
                if (l.type != TypeElem::LP) {
                    qRevPolNot->push(l);
                    output_string += l.symbol;
                }
                else {
                    break;
                }
            }
        }
        else if (l.type == TypeElem::BINARYOP) {
            while (!s->empty()) {
                l1 = s->top(); s->pop();
                if (l1.type == TypeElem::UNARYOP) {
                    qRevPolNot->push(l1);
                    output_string += l1.symbol;
                }
                else if (l1.type == TypeElem::BINARYOP && l1.priority >= l.priority) {
                    qRevPolNot->push(l1);
                    output_string += l1.symbol;
                }
                else {
                    s->push(l1);
                    break;
                }
            }
            s->push(l);
        }
    }
    while (!s->empty()) {
        l = s->top();
        s->pop();
        qRevPolNot->push(l);
        output_string += l.symbol;
    }
    ready = true;
}

double arithmetic_analyzer::calcArithmExp() {
    if (!ready) throw logic_error("The output formula is not ready");
    stack<Lexem>* s = new stack<Lexem>;
    queue<Lexem>* qRevPolNot_tmp = new queue<Lexem>(*qRevPolNot);
    Lexem l, l1, l2;
    double val;
    while (!qRevPolNot_tmp->empty()) {
        l = qRevPolNot_tmp->front(); qRevPolNot_tmp->pop();
        if (l.type == TypeElem::VALUE || l.type == TypeElem::MATH_CONST) {
            s->push(l);
        }
        else if (l.type == TypeElem::VAR) {
            s->push(Lexem(l.symbol, TypeElem::VALUE, (*vars)[l.symbol]));
        }
        else if (l.type == TypeElem::UNARYOP) {
            l1 = s->top(); s->pop();
            if (l.symbol == "-") {
                val = -l1.value;
                s->push(Lexem{ to_string(val), TypeElem::VALUE, val });
            }
            else if (l.symbol == "sin") {
                val = sin(l1.value);
                s->push(Lexem{ to_string(val), TypeElem::VALUE, val });
            }
            else if (l.symbol == "cos") {
                val = cos(l1.value);
                s->push(Lexem{ to_string(val), TypeElem::VALUE, val });
            }
        }
        else if (l.type == TypeElem::BINARYOP) {
            if (l.symbol == "+") {
                l1 = s->top(); s->pop();
                l2 = s->top(); s->pop();
                val = l1.value + l2.value;
                s->push(Lexem{ to_string(val),TypeElem::VALUE, val });
            }
            if (l.symbol == "-") {
                l1 = s->top(); s->pop();
                l2 = s->top(); s->pop();
                val = l2.value - l1.value;
                s->push(Lexem{ to_string(val),TypeElem::VALUE, val });
            }
            if (l.symbol == "*") {
                l1 = s->top(); s->pop();
                l2 = s->top(); s->pop();
                val = l2.value * l1.value;
                s->push(Lexem{ to_string(val),TypeElem::VALUE, val });
            }
            if (l.symbol == "/") {
                l1 = s->top(); s->pop();
                l2 = s->top(); s->pop();
                val = l2.value / l1.value;
                s->push(Lexem{ to_string(val),TypeElem::VALUE, val });
            }
            if (l.symbol == "^") {
                l1 = s->top(); s->pop();
                l2 = s->top(); s->pop();
                val = pow(l2.value, l1.value);
                s->push(Lexem{ to_string(val),TypeElem::VALUE, val });
            }
        }
    }
    val = s->top().value; s->pop();
    return val;
}

#ifndef ARITHMETIC_ANALYZER_H
#define ARITHMETIC_ANALYZER_H

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <queue>
#include <stack>

#if defined( _MSC_VER )
	#define _USE_MATH_DEFINES
	#include<math.h>
#else
	#include<cmath>
#endif

using namespace std;

enum class TypeElem { VALUE, VAR, MATH_CONST, UNARYOP, BINARYOP, LP, RP };
enum State { q0, q1, q2, q3 };

struct Lexem {
	string symbol;
	TypeElem type;
	double value;
	int priority;

	Lexem(const string& _symbol = "-1", TypeElem _type = TypeElem::VALUE, double _value = -1, int _priority = -1)
		: symbol(_symbol), type(_type), value(_value), priority(_priority) { };
};

class arithmetic_analyzer {
private:
	string input_string;
	string output_string;
	bool ready;

	queue<Lexem>* qRevPolNot, * qLexic, * qSyntax;
	map<string, double>* vars;

	Lexem number_analysis(int& current_char);
	Lexem minus_analysis();
	bool sin_analysis(int& current_char, Lexem& l);
	bool cos_analysis(int& current_char, Lexem& l);
	bool pi_analysis(int& current_char, Lexem& l);

	void lexical_analysis();
	void syntactic_analysis();

public:
	arithmetic_analyzer();
	arithmetic_analyzer(const string& str);

	void init(const string& str);

	const string& get_input_string() const;
	const string& get_output_string() const;
	bool isReady() const;
	bool isVars() const;
	int countVars() const;
	bool setVar(const string& name, double value);

	void conversToRevPolNot();
	double calcArithmExp();
};

#endif // ARITHMETIC_ANALYZER_H

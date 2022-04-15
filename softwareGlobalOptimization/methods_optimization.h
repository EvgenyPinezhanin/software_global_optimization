#ifndef METHODS_OPTIMIZATION_H
#define METHODS_OPTIMIZATION_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

enum Stop { ACCURACY, NUMBER, ACCNUMBER };

struct trial {
    double x, z;

    trial(double _x, double _z) : x(_x), z(_z) {};
};

void addInSort(vector<trial>& trials, trial tr);
double searchMinX(const vector<trial>& trials);

class optimization_method {
protected:
    double a, b;
    double eps;
    int Nmax;
    double (*f)(double);

    vector<trial> trial_points;

    virtual double selectNewPoint(size_t &t) = 0;

public:
    optimization_method(double (*_f)(double) = nullptr, double _a = -1.0, double _b = 1.0, double _eps = 0.0001)
        : f(_f), a(_a), b(_b), eps(_eps), Nmax(0) {}

    void setF(double (*_f)(double)) { f = _f; };
    void setA(double _a) { a = _a; };
    void setB(double _b) { b = _b; };
    void setEps(double _eps) { eps = _eps; };

    void getTrialPoints(vector<trial>& trials) const { trials = trial_points; };

    double solve(int& n, Stop stop);
};

class strongin_method : public optimization_method {
private:
    double r;

    double selectNewPoint(size_t& t);

public:
    strongin_method(double (*_f)(double) = nullptr, double _a = -1.0, double _b = 1.0, double _eps = 0.0001, double _r = 2.0);

    void setR(double _r) { r = _r; };
};

class piyavsky_method : public optimization_method {
private:
    double m;

    double selectNewPoint(size_t& t);

public:
    piyavsky_method(double (*_f)(double) = nullptr, double _a = -1.0, double _b = 1.0, double _eps = 0.0001, double _m = 2.0);

    void setM(double _m) { m = _m; };
};

class scan_method : public optimization_method {
private:
    double selectNewPoint(size_t& t);

public:
    scan_method(double (*_f)(double) = nullptr, double _a = -1.0, double _b = 1.0, double _eps = 0.0001);
};

#endif // METHODS_OPTIMIZATION_H

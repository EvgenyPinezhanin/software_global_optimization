#include "methods_optimization.h"

void addInSort(vector<trial>& trials, trial tr) {
    vector<trial>::iterator iter = trials.begin();
    vector<trial>::iterator iterEnd = trials.end();
    while (true) {
        if (iter == iterEnd || iter->x > tr.x) break;
        iter++;
    }
    trials.insert(iter, tr);
}

double searchMinX(const vector<trial>& trials) {
    double z = trials[0].z;
    double x = trials[0].x;
    for (int i = 1; i < trials.size(); i++) {
        if (trials[i].z < z) {
            z = trials[i].z;
            x = trials[i].x;
        }
    }
    return x;
}

double optimization_method::solve(int& n, Stop stop) {
    trial_points.clear();
    if (stop == NUMBER || stop == ACCNUMBER) Nmax = n;
    trial tr(a, f(a));
    trial_points.push_back(tr);
    tr.x = b;
    tr.z = f(b);
    trial_points.push_back(tr);
    n = 2;

    size_t t;
    while (true) {
        n++;
        tr.x = selectNewPoint(t);
        tr.z = f(tr.x);
        addInSort(trial_points, tr);
        if (stop == NUMBER) {
            if (n >= Nmax) break;
        } else if (stop == ACCURACY) {
            if (trial_points[t].x - trial_points[t - 1].x < eps) break;
        } else {
            if (n >= Nmax || trial_points[t].x - trial_points[t - 1].x < eps) break;
        }
    }

    return searchMinX(trial_points);
}

double piyavsky_method::selectNewPoint(size_t& t) {
    double dx = trial_points[1].x - trial_points[0].x;
    double R, Rtmp, x_new;
    R = 0.5 * m * dx - (trial_points[1].z + trial_points[0].z) / 2.0;
    t = 1;
    for (int i = 2; i < trial_points.size(); i++) {
        dx = trial_points[i].x - trial_points[i - 1].x;
        Rtmp = 0.5 * m * dx - (trial_points[i].z + trial_points[i - 1].z) / 2.0;
        if (Rtmp > R) {
            R = Rtmp;
            t = i;
        }
    }
    x_new = 0.5 * (trial_points[t].x + trial_points[t - 1].x) - (trial_points[t].z - trial_points[t - 1].z) / (2.0 * m);
    return x_new;
}

piyavsky_method::piyavsky_method(double (*_f)(double), double _a, double _b, double _eps, double _m)
    : optimization_method(_f, _a, _b, _eps), m(_m) {}

double strongin_method::selectNewPoint(size_t& t) {
    double m, mu, M = 0.0;
    for (int i = 1; i < trial_points.size(); i++) {
        mu = abs(trial_points[i].z - trial_points[i - 1].z) / (trial_points[i].x - trial_points[i - 1].x);
        if (mu > M) M = mu;
    }

    if (M == 0) {
        m = 1.0;
    }
    else {
        m = r * M;
    }

    double dx = trial_points[1].x - trial_points[0].x;
    double R, Rtmp, x_new;
    R = m * dx + pow(trial_points[1].z - trial_points[0].z, 2.0) / (m * dx) - 2.0 * (trial_points[1].z + trial_points[0].z);
    t = 1;

    for (int i = 2; i < trial_points.size(); i++) {
        dx = trial_points[i].x - trial_points[i - 1].x;
        Rtmp = m * dx + pow(trial_points[i].z - trial_points[i - 1].z, 2.0) / (m * dx) - 2.0 * (trial_points[i].z + trial_points[i - 1].z);

        if (Rtmp > R) {
            R = Rtmp;
            t = i;
        }
    }

    x_new = 0.5 * (trial_points[t].x + trial_points[t - 1].x) - (trial_points[t].z - trial_points[t - 1].z) / (2.0 * m);
    return x_new;
}

strongin_method::strongin_method(double (*_f)(double), double _a, double _b, double _eps, double _r)
    : optimization_method(_f, _a, _b, _eps), r(_r) {}


double scan_method::selectNewPoint(size_t& t) {
    double dx, R = 0, Rtmp, x_new;
    t = 0;
    for (int i = 1; i < trial_points.size(); i++) {
        Rtmp = trial_points[i].x - trial_points[i - 1].x;
        if (Rtmp > R) {
            R = Rtmp;
            t = i;
        }
    }
    x_new = 0.5 * (trial_points[t].x + trial_points[t - 1].x);
    return x_new;
}

scan_method::scan_method(double (*_f)(double), double _a, double _b, double _eps) 
    : optimization_method(_f, _a, _b, _eps) {}

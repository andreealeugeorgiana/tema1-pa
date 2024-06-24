#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double f(double a, double b, double x) {
    return a - abs(x-b);
}

bool determine_position(double x1, double x2) {
    if (x1 < x2) {
        return true;
    }
    return false;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int N;
    fin >> N;

    vector<double> P(N);
    vector<double> C(N);

    for (int i = 0; i < N; ++i) {
        fin >> P[i];
    }

    for (int i = 0; i < N; ++i) {
        fin >> C[i];
    }

    double a = P[0], b = C[0];

    for (int i = 1; i < N; i++) {
        if (!determine_position(b, C[i])) {
            swap(a, (P[i]));
            swap(b, (C[i]));
        }
        if ((P[i] - a + b - C[i]) >= 0) {
            continue;
        } else if ((P[i] - a + C[i] - b) <= 0) {
            a = P[i];
            b = C[i];
        } else {
            b = (a + b + C[i] - P[i]) / 2.0;
            a = f(P[i], C[i], b);
        }
    }
    fout << fixed << setprecision(1) << a << endl;
    fin.close();
    fout.close();
}

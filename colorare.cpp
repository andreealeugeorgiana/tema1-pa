#include <fstream>
#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(int to_raise, int exponent) {
    if (exponent == 0)
        return 1;

    long long result = 1;
    long long base = to_raise % MOD;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return result % MOD;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int K;
    fin >> K;

    int x;
    char type;
    unsigned long long int solution = 1;
    char current;

    while (K != 0) {
        fin >> x;
        fin >> type;
        K--;
        if (solution == 1) {
            if (type == 'H') {
                solution = 6;
            } else {
                solution = 3;
            }
            x--;
            current = type;
        }
        if (type == 'H') {
            if (current == 'V') {
                solution = ((solution % MOD) * 2) % MOD;
                x--;
            }
            solution = ((solution % MOD) * (power(3, x) % MOD)) % MOD;
            current = 'H';
        } else if (type == 'V') {
            if (current == 'H') {
                x--;
            }
            solution = ((solution % MOD) * (power(2, x) % MOD)) % MOD;
            current = 'V';
        }
        solution = solution % MOD;
    }
    fout << solution % MOD;

    fin.close();
    fout.close();
}

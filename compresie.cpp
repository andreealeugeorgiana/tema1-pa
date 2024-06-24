#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m, size = 0;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        fin >> b[i];
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            size++;
            i++;
            j++;
        } else {
            if (a[i] < b[j] && i < n-1) {
                a[i+1] = a[i] + a[i+1];
                i++;
            } else if (j < m-1) {
                b[j+1] = b[j] + b[j+1];
                j++;
            }
        }
    }
    if (i < n || size == 0 || j < m) {
        size = -1;
    }
    fout << size;

    fin.close();
    fout.close();
}

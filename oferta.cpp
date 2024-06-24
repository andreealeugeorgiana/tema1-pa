#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

double get_min_price(double a, double b, double c) {
    double minimum = a + b + c;
    if (a + min(b, c)/2 + max(b, c) < minimum) {
        minimum = a + min(b, c)/2 + max(b, c);
    }
    if (min(a, b)/2 + max(a, b) + c < minimum) {
        minimum = min(a, b)/2 + max(a, b) + c;
    }
    if (a + b + c - min(a, min(b, c)) < minimum) {
        minimum = a + b + c - min(a, min(b, c));
    }
    return minimum;
}

double kth_min_price(int N, int K, vector<double>& prices) {
    vector<vector<double>> dp(K+1, vector<double>(N+1, 0));
    dp[0][0] = prices[0];
    dp[0][1] = min(prices[0], prices[1])/2 + max(prices[0], prices[1]);
    dp[0][2] = get_min_price(prices[0], prices[1], prices[2]);

    for (int j = 0; j < K; ++j) {
        for (int i = 3; i < N; ++i) {
            dp[j][i] = dp[j][i-1] + prices[i];
            dp[j][i] = min(dp[j][i],
                    dp[j][i-2] + min(prices[i-1], prices[i])/2
                    + max(prices[i-1], prices[i]));
            dp[j][i] = min(dp[j][i],
                    dp[j][i-3]
                    + get_min_price(prices[i-2], prices[i-1], prices[i]));
        }
    }
    return dp[0][N-1];
}

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int N, K;
    fin >> N >> K;

    vector<double> prices(N);
    for (int i = 0; i < N; ++i) {
        fin >> prices[i];
    }
    double kth_price;
    kth_price = kth_min_price(N, K, prices);
    if (K > N) {
        kth_price = -1;
    }

    fout << fixed << setprecision(1) << kth_price << endl;

    fin.close();
    fout.close();

    return 0;
}

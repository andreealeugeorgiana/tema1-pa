#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_map>

using namespace std;

int get_cost(char letter, string word) {
    int cost = 0;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] != letter) {
            cost--;
        } else {
            cost++;
        }
    }
    return cost;
}

int rucsac(int n, int W, vector<int> &w, vector<int> &p) {
    vector< vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int cap = 0; cap <= W; ++cap) {
            dp[i][cap] = dp[i-1][cap];

            if (cap - w[i - 1] > 0) {
                int sol_aux = dp[i-1][cap - w[i-1]] + p[i-1];

                dp[i][cap] = max(dp[i][cap], sol_aux);
            }
        }
    }

    return dp[n][W];
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int N;
    fin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        fin >> words[i];
    }

    vector<char> letters;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            if (find(letters.begin(), letters.end(), words[i][j])
                == letters.end()) {
                letters.push_back(words[i][j]);
            }
        }
    }
    int passwd = -1;
    for (int i = 0; i < letters.size(); ++i) {
        int total_cost = 0;
        int total_length = 0;
        vector<int> costs;
        vector<int> lengths;
        for (int j = 0; j < N; ++j) {
            int cost = get_cost(letters[i], words[j]);
            if (cost >= 0) {
                total_cost += cost;
                total_length += words[j].size();
            } else {
                costs.push_back(-cost);
                lengths.push_back(words[j].size());
            }
        }
        int max_length = rucsac(costs.size(), total_cost, costs, lengths);
        if (max_length + total_length > passwd) {
            passwd = max_length + total_length;
        }
    }
    fout << passwd << endl;

    fin.close();
    fout.close();
}

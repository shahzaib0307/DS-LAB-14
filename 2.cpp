#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(const string& text, const string& pattern) {
    const int prime = 101;
    const int d = 256;

    int n = text.length();
    int m = pattern.length();

    vector<int> result;
    if (m > n) return result;

    long long hashText = 0;
    long long hashPattern = 0;
    long long h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++) {
        hashPattern = (d * hashPattern + pattern[i]) % prime;
        hashText = (d * hashText + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hashPattern == hashText) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    cout << "False positive at index " << i << "\n";
                    match = false;
                    break;
                }
            }
            if (match) result.push_back(i);
        }

        if (i < n - m) {
            hashText = (d * (hashText - text[i] * h) + text[i + 1]) % prime;
            if (hashText < 0) hashText += prime;
        }
    }

    return result;
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    vector<int> ans = rabinKarp(text, pattern);

    for (int x : ans) cout << x << " ";
    return 0;
}

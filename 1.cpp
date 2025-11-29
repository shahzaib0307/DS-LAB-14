#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<vector<int>, int> bruteForceSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> indices;
    int comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;

        for (int j = 0; j < m; j++) {
            comparisons++;

            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            indices.push_back(i);
        }
    }

    return {indices, comparisons};
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    auto result = bruteForceSearch(text, pattern);

    cout << "Indices: ";
    for (int index : result.first) {
        cout << index << " ";
    }
    cout << "\nTotal Comparisons: " << result.second << endl;

    return 0;
}

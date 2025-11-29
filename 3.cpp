#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildBadChar(string p) {
    vector<int> bad(256, -1);
    for (int i = 0; i < p.size(); i++) bad[p[i]] = i;
    return bad;
}

vector<int> buildSuffix(string p) {
    int m = p.size();
    vector<int> suff(m);
    suff[m-1] = m;
    int g = m-1, f = 0;
    for (int i = m-2; i >= 0; i--) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            g = i;
            f = i;
            while (g >= 0 && p[g] == p[g + m - 1 - f]) g--;
            suff[i] = f - g;
        }
    }
    return suff;
}

vector<int> buildGoodSuffix(string p) {
    int m = p.size();
    vector<int> suff = buildSuffix(p);
    vector<int> gs(m, m);
    int j = 0;
    for (int i = m - 1; i >= 0; i--)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; j++)
                if (gs[j] == m) gs[j] = m - 1 - i;
    for (int i = 0; i <= m - 2; i++)
        gs[m - 1 - suff[i]] = m - 1 - i;
    return gs;
}

vector<int> boyerMoore(string t, string p) {
    vector<int> ans;
    int n = t.size(), m = p.size();
    if (m > n) return ans;

    vector<int> bad = buildBadChar(p);
    vector<int> gs = buildGoodSuffix(p);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && p[j] == t[s + j]) j--;
        if (j < 0) {
            ans.push_back(s);
            s += gs[0];
        } else {
            int bc = j - bad[t[s + j]];
            int gsShift = gs[j];
            s += max(1, max(bc, gsShift));
        }
    }
    return ans;
}

int main() {
    string dna = "ACGTACGTGACG";
    string pattern = "ACG";
    vector<int> pos = boyerMoore(dna, pattern);
    for (int x : pos) cout << x << " ";
}

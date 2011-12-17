#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<string> split(string s) {
    vector<string> res;
    string str;
    s.pb('.');
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '.') {
            if (sz(str) > 50) {
                res.pb(str);
            }
            str.clear();
            continue;
        }
        str.pb(s[i]);
    }
    return res;
}

int main() {
    freopen("raw_poetry.txt", "rt", stdin);
    freopen("poetry.txt", "wt", stdout);
    string str;
    for (int i = 0; i < 10000; ++i) {
        string s;
        cin >> s;
        str += (s + " ");
    }
    vector<string> res = split(str);
    for (int i = 0; i < 10; ++i)
        random_shuffle(all(res));
    for (int i = 0; i < 256; ++i)
        cout << res[i] << endl;
 
    return 0;
}

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

vector<int> get_permutation(string s) {
    vector<int> res;
    set<int> a;
    for (int i = 0; i < 256; ++i)
        a.insert(i);
    for (int i = 0; i < 256; ++i) {
        int sum = 0;
        int x = 1;
        for (int j = 0; j < sz(s); ++j) {
            sum = sum * x + s[j];
            x *= (j + 10);
        }
        sum %= (256 - i);
        if (sum < 0)
            sum += (256 - i);
        //cout << 256 - i << " " << sum << " " << sz(a) << endl;
        set<int>::iterator it = a.begin();
        for (int j = 0; j < sum; ++j) {
            ++it;
        }
        res.pb(*it);
        a.erase(*it);
    }
    return res;
}

vector<int> get_inv_permutation(vector<int> a) {
    vector<int> b(256, 0);
    for (int i = 0; i < 256; ++i)
        b[a[i]] = i;
    return b;
}

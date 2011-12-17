q#include "permutation.h"

#include <iostream>
#include <fstream>
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

int main() {
    fstream f1("encoded.txt", fstream::in);
    fstream f2("decoder.txt", fstream::in);
    fstream f3("poetry.txt", fstream::in);
    freopen("decoded.txt", "wb", stdout); 
    string str;
    string s;
    while (getline(f2, s))
        str += s;
    vector<int> a = get_permutation(str);
    a = get_inv_permutation(a);
    map<string, int> b;
    for (int i = 0; i < 256; ++i) {
        getline(f3, s);
        b[s] = i;
    }
    int i = 0;
    while (getline(f1, s)) {
        int pos = (b[s]) % 256;
        pos = a[pos];
        pos -= i;
        pos %= 256;
        if (pos < 0)
            pos += 256;
        cout << (char)pos;
        ++i;
    }
    
    return 0;
}

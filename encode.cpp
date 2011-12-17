#include "permutation.h"

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
    freopen("text.txt", "rb", stdin);
    fstream f1("decoder.txt", fstream::in);
    fstream f2("poetry.txt", fstream::in);
    freopen("encoded.txt", "wt", stdout); 

    string str;
    string s;
    while (getline(f1, s))
        str += s;
    vector<int> a = get_permutation(str);
    vector<string> b;
    for (int i = 0; i < 256; ++i) {
        getline(f2, s);
        b.pb(s);
    }
    char ch;
    int i = 0;
    while (true) {
        int x = getchar();
        if (x == EOF)
            break;
        ch = x;
        cout << b[a[((ch + i) % 256 + 256) % 256]] << endl;
        ++i;
    }
    
    
    return 0;
}

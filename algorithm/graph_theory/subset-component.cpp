#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

/*     
    problem: 
    category:
    tag:
    url:
    description:
    solution:
    tutorials:
*/

const int nbit = 64;

int bit(unsigned long long x, int i) {
    cout << ((x >> i) & 1) << endl;
    return (x >> i) & 1;
}

bool edge(unsigned long long d, int i, int j) {
    cout << "edge " << d << " " << i << " " << j << endl;
    return bit(d, i) == 1 
           && bit(d, j) == 1;
}

void dfs_visit(vector<unsigned long long> &d, int k, int p, int v, vector<int> &parent) {
    cout << "v: " << v << endl; 
    for (int u = 0; u < 64; u++)
        if (parent[u] == -1) {
            for(int i = k; i <= p; i++) 
                if(edge(d[k], v, u)) {
                    cout << ", u: " << u << endl;                    
                    parent[u] = v;
                    dfs_visit(d, k, p, u, parent);
                    break;
                }
        }
}

unsigned long long subcomponents(vector<unsigned long long> &d, int k, int p) {

    vector<int> parent(nbit, -1);

    int c = 0;
    for(int v = 0; v < nbit; v++) {
        if(parent[v] == -1) {
            parent[v] = 0;
            // cout << endl;
            dfs_visit(d, k, p, v, parent);
            c++;
        }
    }    
    // cout << "c: " << c;
    return c;
}

int main()
{ 
    int n;
    cin >> n;

    vector<unsigned long long> d(n);    
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    unsigned long long total = 64;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // cout << "i: " << i << ", j: " << j << endl;
            total = subcomponents(d, i, j);
            cout << total << endl;
        }
    }

    return 0;
}

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
        synchronous shopping
    category: 
        algorithm/graph_theory
    tag: 
        graph_theory
    url: 
        https://www.hackerrank.com/challenges/synchronous-shopping
    description:
    solution:
    tutorials:
*/

#define N 1e3

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int> > fishes(n);
    vector<list<int >> adj(n);

    vector<vector<int >> costs(n);
    for(auto it = costs.begin(); it != costs.end(); it++)
        it->reserve(n);

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        for (int j = 0; j < t; j++) {
            int a; cin >> a;
            fishes[i].push_back(a);
        }
    }

    for (int i = 0; i < m; i++) {
        int v, u, z;
        cin >> v >> u >> z;
        adj[v].push_back(u);
        adj[u].push_back(v);
        costs[v] = costs[u];
        costs[u] = costs[u];
    }

    return 0;
}
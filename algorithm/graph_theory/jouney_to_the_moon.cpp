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
    problem: journey to the moon
    category: algorithm/graph_theory
    tag: dfs, graph_theory
    url: https://www.hackerrank.com/challenges/journey-to-the-moon
    description:
        You must find all pair of astronauts of different country, 
        where astronauts of the same countries are denoted by the graph P(N, I).
    solution:
        Use DFS to find all the forrest(astronauts of the same country) in the graph then
        for each forrest length Fi we calculate F1xF2 + (F1 + F2)xF3 + ... + (F1 + ... + Fi-1)xFi
    tutorials:
        https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/lecture-14-depth-first-search-dfs-topological-sort/
        https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec14.pdf
*/
map<int,int> parent;

int dfs_visit(vector<vector<int >> &adj, int v) {
    int s = 0;
    for (int u = 0; u < adj[v].size(); u++) {
        if(parent.find(adj[v][u]) == parent.end()) {
            parent[adj[v][u]] = v;
            s += dfs_visit(adj, adj[v][u]);
        }
    }
    return s + 1;
}

unsigned long long dfs(int V, vector<vector<int >> &adj) {
    unsigned long long sum_nodes = 0;
    unsigned long long sum = 0;
    for(int v = 0; v < V; v++) {
        if(parent.find(v) == parent.end()) {
            parent[v] = -1;
            int nodes = dfs_visit(adj, v);
            sum = sum + sum_nodes*nodes;
            sum_nodes += nodes;
        }
    }
    return sum;
}

int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 0;
    result = dfs(N, pairs);
    cout << result << endl;
    return 0;
}

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
        Breadth First Search: Shortest Reach
    category:
        algorithms/graph_theory 
    tag:
        bfs,
    url:
        https://www.hackerrank.com/challenges/bfsshortreach
    description:
        Consider an undirected graph consisting of  nodes where each node is 
        labeled from 1 to n and the edge between any two nodes is always of 
        length 6. We define node s to be the starting position for a BFS.
    solution:
        Compute bfs over de graph G and use levels array to calculate the 
        length to s from every node.
    tutorials:
        https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec13.pdf
*/


void shortest_reach(vector<list<int> > &G, int n, int s) {

    set<int> frontier;
    vector<int> parent(n, -1);
    vector<int> level(n, -1);    
    fontier.insert(s);
    int l = 1;

    while (!frontier.empty() {
        set<int> next;
        for(auto v = frontier.begin(); v != frontier.end(); ++v) {
            for (auto u = G[*v].begin(); u != G[*v].end(); u++) {
                if(parent[*u] == -1) {
                    next.insert(*u);
                    parent[*u] = *v;
                    level[*u] = l;
                }
            }
        }
        l++;
        frontier = next;
    }

    for(int i = 1; i <= n; i++) {
        if (i != s)
         cout << level[i] << " "
    }
    cout << endl;
}

int main()
{ 
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<list<int> > G(n);    
        while (m--) {
            int u, v;
            cin >> u >> v;            
            pairs[u].push_back(v);
            pairs[v].push_back(u);
        }
        int s;
        cin >> s;
        shortest_reach(G, n, s);
    }

    return 0;
}

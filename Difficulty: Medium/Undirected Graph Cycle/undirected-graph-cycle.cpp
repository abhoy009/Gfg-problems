//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    bool detect(int src, vector<int> adj[], vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;  // {node, parent}
        
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            // Traverse all adjacent nodes of the current node
            for (auto adjnode : adj[node]) {
                // If the adjacent node is not visited, visit it
                if (!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, node});
                }
                // If the adjacent node is already visited and is not the parent of the current node,
                // then there's a cycle
                else if (parent != adjnode) {
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Visited array to mark visited nodes
        vector<int> vis(V, 0);
        
        // Traverse each node to ensure all components are covered
        for (int i = 0; i < V; i++) {
            // If node is not visited, start a BFS/DFS from it
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;  // If no cycle is found
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of a given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsResult;   // To store the result of BFS traversal
        vector<bool> visited(V, false);  // To keep track of visited nodes
        
        // Queue for BFS
        queue<int> q;
        
        // Assuming we start BFS from node 0
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Add this node to the result
            bfsResult.push_back(node);
            
            // Explore all adjacent nodes
            for(auto neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return bfsResult;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
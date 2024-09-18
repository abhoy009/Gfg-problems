//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Helper function to perform DFS
    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& dfsResult) {
        // Mark the current node as visited
        visited[node] = true;
        // Store the current node in the DFS result
        dfsResult.push_back(node);
        
        // Visit all the adjacent nodes of the current node
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, dfsResult);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfsResult;  // To store the DFS traversal
        vector<bool> visited(V, false);  // To keep track of visited nodes
        
        // Assuming we start DFS from node 0
        dfs(0, adj, visited, dfsResult);
        
        return dfsResult;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
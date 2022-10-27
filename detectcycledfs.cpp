 bool isCycle(vector<int> adj[], int p,unordered_map<int,bool> &vis, int node){

      vis[node] = true;

      for(auto it: adj[node]){

          if(!vis[it]){

              bool ans = isCycle(adj, node, vis, it);

              if(ans) return true;

          }

          else if(it != p) return true;

      }

      return false;

  }

    // Function to detect cycle in an undirected graph.

    bool isCycle(int V, vector<int> adj[]) {

        unordered_map<int, bool> vis;

        for(int i=0;i<V;i++){

            if(!vis[i]){

                bool ans = isCycle(adj, -1,vis, i);

                if(ans) return true;

            }

        }

        return false;

    }

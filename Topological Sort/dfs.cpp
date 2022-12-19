//Topological Sorting using DFS Based Algorithm

//Algorithm:

//We can modify DFS to find Topological Sorting of a graph. In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices.
//In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack.
//Finally, print contents of the stack.
//Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack.

// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution{
public:
	void topo(vector<int> adj[], int u, bool visited[], stack<int> &s) {
        visited[u] = true; 
    
        //traversing over the adjacent vertices.
        for (auto v : adj[u]){
            //if any vertex is not visited, we call the function recursively.
            if (!visited[v])
                topo(adj, v, visited,s); 
        }
        
        //pushing the current vertex into the stack.
        s.push(u); 
    }
    
    
    vector <int> topoSort(int N, vector<int> adj[]) {
        bool visited[N + 1];                
        memset(visited, 0, sizeof visited); 
        
        stack<int> s;
        
        for (int i = 0; i < N; i++) {
            //if the current vertex is not visited, we call the topo function.
            if (!visited[i])              
                topo(adj, i, visited, s); 
        }
    
        vector<int> res;
        int i = -1;
        while (!s.empty()){
            //pushing elements of stack in list and popping them from stack.
            res.push_back(s.top()); 
            s.pop();
        }
        //returning the list.
        return res;
    }
};

bool bfs(int value , vector<int> adj[] , vector<int> &visited)

   {

       queue<pair<int,int>> q;

       q.push(make_pair(-1,value));

        while(!q.empty())

        {

            pair<int,int> temp = q.front();

            q.pop();

            int node = temp.second;

            int parent = temp.first;

            

            vector<int> v = adj[node];

            for(int i=0 ;i<v.size() ;i++)

            {

                if(visited[v[i]]!=1)

                {
                    visited[v[i]] = 1;
                    q.push(make_pair(node , v[i]));
                }
                else if(visited[v[i]] == 1 && v[i]!=parent)
                    return true;
                else
                    continue;
            }

        }

        return false;

   }

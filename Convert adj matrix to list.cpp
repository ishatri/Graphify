 vector<int> adjlist[V+1];
        for(int i =0;i<V;i++)
        {
            for(int j =0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    adjlist[i+1].push_back(j+1);
                }
            }
        }

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
     int n = grid.size();
        int m = grid[0].size();
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        vector<vector<int>> vist(n, vector<int>(m, 0));
		// BFS
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(!vist[i][j] && grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vist[i][j] = 1;
                    }
                    
                }
            }
        }
       
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(r >= 0 && r < n && c >= 0 && c < m && !vist[r][c] && grid[r][c] == 1)
                {
                    q.push({r, c});
                    vist[r][c] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vist[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};

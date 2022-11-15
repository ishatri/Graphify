class solution{
  public:

void dfs(vector<vector<int>>&grid,int i,int j){
     
       if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
       return;
       grid[i][j]=0;
       dfs(grid,i+1,j);
       dfs(grid,i-1,j);
       dfs(grid,i,j-1);
       dfs(grid,i,j+1);
       return ;
       
       
       
       
       
   }
 
 
   int numberOfEnclaves(vector<vector<int>> &grid) {
       // Code here
       for(int i=0;i<grid.size();i++){
           dfs(grid,i,0);
       }
       for(int j=1;j<grid[0].size();j++){
           dfs(grid,0,j);
       }
       for(int i=1;i<grid.size();i++){
           dfs(grid,i,grid[0].size()-1);
       }
       for(int j=1;j<grid[0].size();j++){
           dfs(grid,grid.size()-1,j);
       }
       int count=0;
       for(auto i: grid){
           for(auto j: i){
               if(j==1)
               count++;
           }
       }
       return count;
       
   }
};

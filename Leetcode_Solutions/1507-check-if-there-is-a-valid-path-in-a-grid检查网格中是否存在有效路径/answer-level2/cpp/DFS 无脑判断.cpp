逐一判断每一种可能的情况，遇到n-1与m-1 即说明有解
```
class Solution {
public:
	bool update=false;
    bool hasValidPath(vector<vector<int>>& grid) {
        DFS(grid,0,0);
        return update;
    }
    void DFS(vector<vector<int>>& grid,int x,int y)
    {
        int n=grid.size(),m=grid[0].size();
        if(x==n-1&&y==m-1) update=true;
    	if(update) return ;
    	if(grid[x][y]==1)
    	{
    		grid[x][y]=8;
    		if(y-1>=0&&(grid[x][y-1]==6||grid[x][y-1]==4||grid[x][y-1]==1))
			    DFS(grid,x,y-1);
    		if(y+1<m&&(grid[x][y+1]==3||grid[x][y+1]==5||grid[x][y+1]==1))
    			DFS(grid,x,y+1);
    		grid[x][y]=8;
        }
        if(grid[x][y]==2)
    	{
    		grid[x][y]=8;
    		if(x-1>=0&&(grid[x-1][y]==3||grid[x-1][y]==4||grid[x-1][y]==2))
    			DFS(grid,x-1,y);
    		if(x+1<n&&(grid[x+1][y]==6||grid[x+1][y]==5||grid[x+1][y]==2))
    	        DFS(grid,x+1,y);
    		grid[x][y]=8;
        }
        if(grid[x][y]==3)
    	{
    		grid[x][y]=8;
    		if(x+1<n&&(grid[x+1][y]==6||grid[x+1][y]==5||grid[x+1][y]==2))
    		    DFS(grid,x+1,y);
    		if(y-1>=0&&(grid[x][y-1]==4||grid[x][y-1]==6||grid[x][y-1]==1))
    		    DFS(grid,x,y-1);
    		grid[x][y]=8;
        }
        if(grid[x][y]==4)
    	{
    		grid[x][y]=8;
    		if(y+1<m&&(grid[x][y+1]==1||grid[x][y+1]==5||grid[x][y+1]==3))
    		    DFS(grid,x,y+1);
    		if(x+1<n&&(grid[x+1][y]==2||grid[x+1][y]==6||grid[x+1][y]==5))
    		    DFS(grid,x+1,y);
    		grid[x][y]=8;
        }
        if(grid[x][y]==5)
    	{
    		grid[x][y]=8;
    		if(x-1>=0&&(grid[x-1][y]==2||grid[x-1][y]==3||grid[x-1][y]==4))
    		    DFS(grid,x-1,y);
    		if(y-1>=0&&(grid[x][y-1]==4||grid[x][y-1]==6||grid[x][y-1]==1))
    		    DFS(grid,x,y-1);
    		grid[x][y]=8;
        }
        if(grid[x][y]==6)
    	{
    		grid[x][y]=8;
    		if(y+1<m&&(grid[x][y+1]==1||grid[x][y+1]==5||grid[x][y+1]==3))
    	   	    DFS(grid,x,y+1);
    		if(x-1>=0&&(grid[x-1][y]==2||grid[x-1][y]==3||grid[x-1][y]==4))
    		    DFS(grid,x-1,y);
    		grid[x][y]=8;
        }
	}
};
```

直接枚举每个点，然后开始深搜，当然，遍历过的点不要重复遍历，然后找到若干被包围的块即可。
```
class Solution {
	
	int ans;
	boolean[][] flag;
	boolean mark;
	int[] dx= {1,-1,0,0};
	int[] dy= {0,0,1,-1};
	
    public int closedIsland(int[][] grid) {
    	int n=grid.length;
    	if(n==0) return 0;
    	int m=grid[0].length;
    	if(m==0) return 0;
    	ans=0;
    	flag=new boolean[n][m];
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++) {
    			if(flag[i][j] || grid[i][j]==1)
    				continue;
    			mark=false;
    	    	flag[i][j]=true;
    			dfs(grid,i,j,n,m);
    			if(mark==false)
    				ans++;
    		}
    	return ans;
    }
    
    private void dfs(int[][] grid,int x,int y,int n,int m) {
    	for(int i=0;i<4;i++) {
    		int xx=x+dx[i];
    		int yy=y+dy[i];
    		if(xx<0 || xx>=n || yy<0 || yy>=m) {
    			mark=true;
    			continue;
    		}
    		if(flag[xx][yy] || grid[xx][yy]==1) continue;
    		flag[xx][yy]=true;
    		dfs(grid,xx,yy,n,m);
    	}
    }
}

```

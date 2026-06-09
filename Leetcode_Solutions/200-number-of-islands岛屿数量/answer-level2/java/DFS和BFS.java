### 解题思路
此处撰写解题思路
两种方法：1、BFS：2、DFS
相同点是都要遍历数组找到第一块陆地，然后开始查找相邻的陆地，一种是直接找上下左右，就是BFS；另一种是找上，接着上，直到上找完了，再找下，下找完了在找左，也就是DFS。其他就是边界问题和找到的陆地变成海洋。
### 代码

```java
class Solution{
    public int numIslands(char[][] grid) {
    	if(grid.length==0) return 0;
    	int count = 0;
        int m = grid.length;
        int n = grid[0].length;
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		if(grid[i][j]=='1') {
        			count = count+1;//先找到第一块陆地
        			ppp(i,j,grid);
        		}
        	}
        }
        return count;
    }
   public void ppp(int i,int j,char[][] grid) {
	   if(grid[i][j]=='1') {
		  grid[i][j]='0';
		  if(i-1>=0&&i-1<grid.length) ppp(i-1,j,grid);
		  if(i+1>=0&&i+1<grid.length) ppp(i+1,j,grid);
		  if(j-1>=0&&j-1<grid[0].length) ppp(i,j-1,grid);
		  if(j+1>=0&&j+1<grid[0].length) ppp(i,j+1,grid);
	   }
   }
}
```
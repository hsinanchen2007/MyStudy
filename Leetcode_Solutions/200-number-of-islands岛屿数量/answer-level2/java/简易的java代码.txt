### 代码

```java
class Solution {
    public int numIslands(char[][] grid){
		if(grid.length == 0){
			return 0;
		}
		// 深度优先搜索
		int res = 0;
		for(int i=0;i<grid.length;i++){
			for(int j=0;j<grid[0].length;j++){
				res = res + bfs(grid,i,j);
			}
		}
		return res;
	}
	
	public int bfs(char[][] grid,int i,int j){
		if(grid[i][j] == '1'){
			grid[i][j] = '2';// 2用来标记遍历过的陆地块，防止后面的bfs“转圈圈”
			if(i-1>=0){
				bfs(grid,i-1,j);
			}
			if(i+1<grid.length){
				bfs(grid,i+1,j);
			}
			if(j-1>=0){
				bfs(grid,i,j-1);
			}
			if(j+1<grid[i].length){
				bfs(grid,i,j+1);
			}
			return 1;
		}
		return 0;
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/97af6298932bd70a35e62fe4d2627ec7bd326b09fcde623c24da6cd8bfc2a943-wechat.png)

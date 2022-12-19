第一次写题解，好激动啊！！
我用DFS写的，要点就是： **DFS 4个方向，取4个方向的最小值返回**
当然，dfs过程中，需要用visited记录我去过这个点了（假设为点A），这样从A出发的这条路径，就不会再回到A了。
然后A的4个方向都已经遍历完之后，还要重新还原A的visited的状态，因为其他路径的DFS还要走A，不还原状态的话，别的路也不会再走到A了，所以要还原。（类似于回溯的时候，状态也要还原）
结合注释看，思路应该算还好理解

```java
    public int shortestPath(int[][] grid, int k) {
        int len = grid.length,col = grid[0].length;
        if (k >= len + col -3) return len+col-2;     //没有这句，超时
        boolean[][] visited = new boolean[len][col];  //避免dfs发生原路返回的情况
        int result = shortestPathDfs(grid,0,0,len,col,0,k,visited);
        return result == Integer.MAX_VALUE ? -1 : result;
    }
    
    public int shortestPathDfs(int[][] grid,int i,int j,int row,int col,int covered,int k,boolean[][] visited) {
        if (i < 0 || i >= row || j < 0 || j >= col) return Integer.MAX_VALUE; //递归出口
        if (i == row-1 && j == col-1) return covered;   //递归出口，结果
        if (visited[i][j]) return Integer.MAX_VALUE; //递归出口
        
        if (grid[i][j] == 1) {
            if (k > 0) k--;   //k做出牺牲，让1变为0
            else return Integer.MAX_VALUE; //k已经为0了，但是此块为1，则是一条死路
        }
        
        visited[i][j] = true;  //记录这条路径上这个节点已经访问过
        
        //取4个方向上可能路径的最小值返回
        int minOf4Dicrect = Integer.MAX_VALUE;
        minOf4Dicrect = Math.min(minOf4Dicrect,shortestPathDfs(grid,i-1,j,row,col,covered+1,k,visited));
        minOf4Dicrect = Math.min(minOf4Dicrect,shortestPathDfs(grid,i+1,j,row,col,covered+1,k,visited));
        minOf4Dicrect = Math.min(minOf4Dicrect,shortestPathDfs(grid,i,j+1,row,col,covered+1,k,visited));
        minOf4Dicrect = Math.min(minOf4Dicrect,shortestPathDfs(grid,i,j-1,row,col,covered+1,k,visited));
        
        visited[i][j] = false; //回溯
        return minOf4Dicrect;
    }
```

![4147FF53-5FB5-40E4-AAC4-6AF446B6F776.png](https://pic.leetcode-cn.com/455caaf0da3b1be9cb688f8c7f1641a816685913d1315de053993e590ccf0713-4147FF53-5FB5-40E4-AAC4-6AF446B6F776.png)


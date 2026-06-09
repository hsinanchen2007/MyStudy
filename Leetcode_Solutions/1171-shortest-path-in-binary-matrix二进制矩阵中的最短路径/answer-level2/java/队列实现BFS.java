![image.png](https://pic.leetcode-cn.com/1aa4d9cb2678aff422a0563719e9719a54651506e9838ff597e241378ca87042-image.png)
广度优先搜索算法:按照离右下角的距离从小到大开始搜索，最先到达grid[0][0]的长度即为答案
```
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int i, j , length, N;
        int[] next;
        Queue<int[]> queue;
        
        N = grid.length;
        if(N == 0)
            return -1;
        if(grid[N-1][N-1] == 1 || grid[0][0] == 1)
            return -1;
        queue = new LinkedList<>();
        grid[N-1][N-1] = -1;
        queue.add(new int[]{N - 1, N - 1});
        while(!queue.isEmpty()){
            next = queue.remove();
            i = next[0];
            j = next[1];
            if(i == 0 && j == 0)
                return -grid[0][0];
            length = grid[i][j] - 1;
            check(grid, i - 1, j, length, queue);
            check(grid, i - 1, j - 1, length, queue);
            check(grid, i - 1, j + 1, length, queue);
            check(grid, i + 1, j, length, queue);
            check(grid, i + 1, j - 1, length, queue);
            check(grid, i + 1, j + 1, length, queue);
            check(grid, i, j + 1, length, queue);
            check(grid, i, j - 1, length, queue);
        }
        return -1;
    }
    
    private void check(int[][] grid, int i, int j, int length, Queue<int[]> queue){
        if(i > -1 && i < grid.length && j > -1 && j < grid.length && grid[i][j] == 0){
            grid[i][j] = length;
            queue.add(new int[]{i, j});
        }
    }
}
```

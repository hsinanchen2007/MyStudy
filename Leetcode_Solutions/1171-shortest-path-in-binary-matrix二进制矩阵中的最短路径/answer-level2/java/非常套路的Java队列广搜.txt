队列+状态判重，很典型的套路。

就是需要首先判断初始状态可不可达

```
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        
        int[][] state = new int[m][n];
        
        Deque<Integer> queue = new LinkedList<Integer>();
        
        
        //略坑，如果左上角为1，则直接不可到达
        if(grid[0][0] == 1)
            return -1;
        
        //初始状态
        state[0][0] = 1;
        queue.addLast(0);
        
        //定义八个方向
        int direction[][] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        while(queue.size() != 0){
            int tmp = queue.removeFirst();
            int row = tmp / m;
            int col = tmp % m;
            
            for(int i = 0; i<direction.length; i++){
                int new_row = row + direction[i][0];
                int new_col = col + direction[i][1];
                
                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] == 0 && state[new_row][new_col] == 0){
                    
                    //如果满足条件，则记录状态并加入到队列中
                    state[new_row][new_col] = state[row][col] + 1;
                    queue.addLast(m * new_row + new_col);
                    
                    //判断是否为目标状态
                    if(new_row == m-1 && new_col == n-1){
                        return state[new_row][new_col];
                    }
                }
            }
        }
        
        
        return -1;
        
    }
}
```
以 3 作为分隔符
```
class Solution {
    Queue<int[]> queue = new LinkedList<>();
    public int orangesRotting(int[][] grid) {
        int row_len = grid.length;
        int col_len = grid[0].length;

        for(int i = 0; i < row_len; i++){
            for(int j = 0; j < col_len; j++){
                if(grid[i][j] == 2){
                    queue.offer(new int[]{i, j});
                }
            }
        }
        
        int count = 0;
        queue.offer(new int[]{3});

        while(!queue.isEmpty()){
            int[] index  = queue.poll();
            count_lost_1++;
            if(index.length == 1){
                if(!queue.isEmpty()) {
                    queue.offer(new int[]{3});
                    count++;
                }

                continue;
            }
            search(queue, grid, index);
        }

        for(int i = 0; i < row_len; i++){
            for(int j = 0; j < col_len; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return count;
    }

    public void search(Queue queue, int[][] grid, int[] index){
        int m = index[0];
        int n = index[1];
        if(m != 0){
            if(grid[m - 1][n] == 1){
                queue.offer(new int[]{m - 1, n});
                grid[m - 1][n] = 2;
            }

        }
        if(m != grid.length - 1){
            if(grid[m + 1][n] == 1){
                queue.offer(new int[]{m + 1, n});
                grid[m + 1][n] = 2;
            }
        }
        if(n != 0){
            if(grid[m][n - 1] == 1){
                queue.offer(new int[]{m, n - 1});
                grid[m][n - 1] = 2;
            }
        }
        if(n != grid[0].length - 1){
            if(grid[m][n + 1] == 1){
                queue.offer(new int[]{m, n + 1});
                grid[m][n + 1] = 2;
            }
        }
    }
}
```

```
class Solution {
    Queue<Integer> targets = new LinkedList();
    public int maxDistance(int[][] grid) {
        for(int row = 0; row < grid.length; row++){
            for(int col = 0; col < grid[row].length; col++){
                if(grid[row][col] == 1){
                    findOcean(grid, row, col, -1);
                }
            }
        }
        if(targets.isEmpty()){
            return -1;
        }
        int dis = 0;
        while(!targets.isEmpty()){
            int row = targets.poll();
            int col = targets.poll();
            dis = Math.max(dis, -grid[row][col]);
            // System.out.println("row: " + row);
            // System.out.println("col: " + col);
            // System.out.println("dis: " + dis);
            // System.out.println("-----------------");
            findOcean(grid, row, col, grid[row][col] -1);
        }
        return dis;
        
    }

    public boolean findOcean(int[][] grid, int row, int col, int dis){
        if(row - 1 >= 0){
            if(grid[row-1][col] == 0){
                grid[row - 1][col] = dis;
                targets.offer(row - 1);
                targets.offer(col);
            }
        }
        if(row + 1 < grid.length){
            if(grid[row+1][col] == 0){
                grid[row+1][col] = dis;
                targets.offer(row + 1);
                targets.offer(col);
            }
        }
        if(col - 1 >= 0){
            if(grid[row][col-1] == 0){
                grid[row][col-1] = dis;
                targets.offer(row);
                targets.offer(col - 1);
            }
        }
        if(col + 1 < grid.length){
            if(grid[row][col+1] == 0){
                grid[row][col+1] = dis;
                targets.offer(row);
                targets.offer(col + 1);
            }
        }
        return true;
    }
}
```

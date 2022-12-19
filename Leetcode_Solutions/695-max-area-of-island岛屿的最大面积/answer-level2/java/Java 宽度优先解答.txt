```
class Coordinate{
    int x, y;
    public Coordinate (int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int maxAreaOfIsland(int[][] grid) { 
        if(grid == null || grid.length < 1 || grid[0].length < 1){
            return 0;
        }
        int maxArea = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    int temp = markByBFS(grid, i, j);
                    if(temp > maxArea){
                        maxArea = temp;
                    }
                }
            }
        }
        return maxArea;
    }
    private int markByBFS (int[][] grid, int i, int j){
        int[] xCoordinate = {-1, 0, 0, 1};
        int[] yCoordinate = {0, -1, 1, 0};
        Queue <Coordinate> queue = new LinkedList <>();
        queue.offer(new Coordinate(i, j));
        grid[i][j] = 0;
        int currentArea = 1;
        while(!queue.isEmpty()){
            Coordinate temp = queue.poll();
            for(int a = 0; a < 4; a++){
                Coordinate neighbor = new Coordinate(temp.x + xCoordinate[a],
                                            temp.y + yCoordinate[a]);
                if(!isInBound(grid, neighbor)){
                    continue;
                }
                if(grid[neighbor.x][neighbor.y] == 1){
                    grid[neighbor.x][neighbor.y] = 0;
                    queue.offer(neighbor);
                    currentArea++;
                }
            }
        }
        return currentArea;
    }
    private boolean isInBound (int[][] grid, Coordinate coor){
        int m = grid[0].length;
        int n = grid.length;
        return coor.x >= 0 && coor.x < n && coor.y >= 0 && coor.y < m;
    }
}
```

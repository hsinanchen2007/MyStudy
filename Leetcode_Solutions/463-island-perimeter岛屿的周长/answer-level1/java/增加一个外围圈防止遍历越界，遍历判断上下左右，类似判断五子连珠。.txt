执行用时 :11 ms, 在所有 Java 提交中击败了96.12%的用户
内存消耗 :58.6 MB, 在所有 Java 提交中击败了94.78%的用户
```
class Solution {
    public int islandPerimeter(int[][] grid) {
        int [][] newGrid = new int [grid.length+2][grid[0].length+2];
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                newGrid[i+1][j+1] = grid[i][j];
            }
        }
        int sum = 0;
        for (int i = 0; i < grid.length; i++){
            for (int j = 0;j < grid[i].length; j++){
                if (newGrid[i+1][j+1] == 1){
                    sum += (4-newGrid[i+1][j] - newGrid[i+1][j+2] - newGrid[i][j+1] - newGrid[i+2][j+1]);
                }
                
            }
        }
        return sum;
    }
}
```

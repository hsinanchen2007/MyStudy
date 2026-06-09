两次循环，时间复杂度O(m*n)
```
class Solution {
    public int countNegatives(int[][] grid) {
        int count = 0;
        for(int i = 0; i <grid.length;i++){
            for(int j = 0; j <grid[i].length;j++ ){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }
        return count;
    }
}
```

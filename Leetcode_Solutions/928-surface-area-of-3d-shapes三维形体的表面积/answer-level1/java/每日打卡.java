### 解题思路
关键在于理解题意
### 代码

class Solution {
    public int surfaceArea(int[][] grid) {
        /*题目理解有点困难。看了评论区大佬的题意分析，总算明白了题意
        grid[i]数组的下标表示单元格的横坐标
        grid[i][j]中的下标表示单元格的纵坐标，值表示立方体的个数
        */
        int sum = 0;//统计正方体总个数
        int count = 0;//统计重合的次数
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length;j++){
                sum += grid[i][j];
                //若grid[i][j]大于1，则会有grid[i][j]-1次出现边的重合
                if(grid[i][j] > 1){
                    count += grid[i][j] - 1;
                }
                //同一横坐标下，每相邻两个立方体会重合min(grid[i][j], grid[i][j+1])次
                if(j + 1 < grid[0].length){
                    count += Math.min(grid[i][j], grid[i][j+1]);
                }
                //同一纵坐标下，每相邻两个立方体会重合min(grid[i][j],grid[i+1][j]次
                if(i + 1 < grid.length){
                    count += Math.min(grid[i][j],grid[i+1][j]);
                }
            }
        }
        return sum*6 - count*2;
    }
}
```
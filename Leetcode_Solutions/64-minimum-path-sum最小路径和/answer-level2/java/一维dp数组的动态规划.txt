### 解题思路
经典的动态规划题目，后一个状态由前面的状态推出。
刚开始用Python写的一遍通过，当时用的dp数组是二维的，正好对应题目给定的二维数组。
但后来想了想，存储同样数据的二维数组内存占用要比一维数组大，即dp[2][2]占用空间要比dp[4]大很多，
所以可以考虑把二维的dp[row][col]数组转换成dp[row*col]解决，
这样对应二维数组的索引为dp[i][j] = dp[i * col + j]，
其余与一般的动态规划解题思路相同。

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int row = grid.length;
        if(row == 0){
            return 0;               //判空
        }
        int col = grid[0].length;
        if(col == 0){
            return 0;               //再次判空
        }
        int[] dp = new int[row*col];        //采用一维数组dp[]取代二维数组dp[][]。
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i==0 && j==0){
                    dp[i*col+j] = grid[i][j];       //dp[0] = grid[0][0]
                }
                else if(i==0){
                    dp[i*col+j] = dp[i*col+(j-1)]+grid[i][j];
                }
                else if(j==0){
                    dp[i*col+j] = dp[(i-1)*col+j]+grid[i][j];
                }
                else{
                    dp[i*col+j] = Math.min(dp[i*col+(j-1)], dp[(i-1)*col+j]) + grid[i][j];
                }
            }
        }
        return dp[(row-1)*col+(col-1)];     //对应二维数组的状态dp[row-1][cow-1]，其实就是dp[row*cow-1]，dp[]的最后一位。
    }
}
```
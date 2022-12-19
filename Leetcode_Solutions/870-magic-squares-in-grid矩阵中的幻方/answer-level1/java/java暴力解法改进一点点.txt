感觉自己太菜了，只能暴力呀！

满足条件的和只能是15，且3x3矩阵中心数字必须为5;

同时数字不能重复，还要判断数字在1到9之间，可以用除10取余来判断是否在1到9之间。

```java
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        if(grid.length <= 2 || grid[0].length <= 2) return 0;
        int count = 0;
        for(int i = 0; i <= grid.length-3; i++){
            for(int j = 0; j <= grid[0].length-3; j++){
                if(grid[i+1][j+1] == 5){
                    if(grid[i][j] == 5) continue;
                    else{
                        int sum1 = grid[i][j]%10 + grid[i+2][j+2]%10 + 5;
                        int sum2 = grid[i][j+1]%10 + grid[i+2][j+1]%10 + 5;
                        int sum3 = grid[i][j+2]%10 + grid[i+2][j]%10 + 5;
                        int sum4 = grid[i+1][j]%10 + grid[i+1][j+2]%10 + 5;
                        int sum5 = grid[i][j]%10 + grid[i][j+1]%10 + grid[i][j+2]%10 ;
                        int sum6 = grid[i+2][j]%10 + grid[i+2][j+1]%10 + grid[i+2][j+2]%10;
                        int sum7 = grid[i][j]%10 + grid[i+1][j]%10 + grid[i+2][j]%10;
                        int sum8 = grid[i][j+2]%10 + grid[i+1][j+2]%10 + grid[i+2][j+2]%10;
                        if(15 == sum1 && sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 &&
                           sum5 == sum6 && sum6 == sum7 && sum7 == sum8 ){
                            count++;
                        } 
                    }
                    
                }
            }
        }
        return count;
    }
}
```
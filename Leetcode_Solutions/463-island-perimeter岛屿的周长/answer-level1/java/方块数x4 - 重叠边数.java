### 解题思路

新手代码
执行用时 :15 ms, 在所有 Java 提交中击败了11.30%的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了100.00%的用户

目的就把题目的二元组放入一个大一圈的二元组减少判断
然后方块数x4的周长减去重叠的边数

虽然内存消耗降低了但是执行用时变长了

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int rowA = grid[0].length;
        int lenA = grid.length;
        //
        int sum = 0;
        for(int n[] : grid)
            for(int m : n) sum += m;
        sum = sum * 4;
        //做一个大一圈的二元组，减少边界判断
        int[][] b = new int[lenA + 2][rowA + 2];
        for(int n = 0; n < lenA; n++){
            for(int m = 0; m < rowA; m++){
                b[n + 1][m + 1] = grid[n][m];
            }
        }
        
        for(int n = 1; n <= lenA; n++){
            for(int m = 1; m <= rowA; m++){
                //
                if(b[n][m] == 1){
                    if(b[n - 1][m] == 1 ) sum -= 1;
                    if(b[n][m - 1] == 1 ) sum -= 1;
                    if(b[n + 1][m] == 1 ) sum -= 1;
                    if(b[n][m + 1] == 1 ) sum -= 1;
                }
            }
        }
        return sum;
    }
}

```
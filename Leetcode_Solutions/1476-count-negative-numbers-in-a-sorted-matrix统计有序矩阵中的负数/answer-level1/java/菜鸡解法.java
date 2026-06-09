### 解题思路
此处撰写解题思路
最小值一定在右下角，以此为突破点进行遍历。还有优化空间。
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length;  //hang
        int n = grid[0].length;  //lie
        int count = 0;
        for(int i = m-1 ; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] < 0){
                    count ++;
                }
                else{
                    break;
                }
            }
        }
        return count;

    }
}
```
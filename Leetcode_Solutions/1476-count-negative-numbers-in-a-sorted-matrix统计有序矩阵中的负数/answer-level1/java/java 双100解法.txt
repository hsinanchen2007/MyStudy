### 解题思路
嵌套循环，碰到负数就跳过之后的

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        for(int i = 0; i < m; i++){
            if(grid[i][0] < 0){
                count += (m - i) * n;
                break;
            }
            for(int j = 0; j< n; j++){
                if(grid[i][j] < 0){
                    count += n - j;
                    break;
                }
            }
        }
        return count;
    }
}
```
### 解题思路
逐行遍历，每一行遍历到第一个负数就可以计算该行了

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int rowcount = grid.length;
        int colcount = grid[0].length;
        int count = 0;
        for(int i = 0; i < rowcount; i++){
            for(int j = 0; j < colcount; j++){
                if(grid[i][j] < 0){
                    count += colcount - j;
                    break;
                }
            }
        }
        return count;
    }
}
```
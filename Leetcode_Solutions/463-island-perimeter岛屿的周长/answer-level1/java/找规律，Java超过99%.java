### 解题思路

通过看图找到规律，按照图形情况，如果1周围上下左右是0则边数加1:

1. 上边界：如果是第0行则加1，否则判断`i-1`为0则边数+1
2. 下边界：如果是最后一行则加1，否则判断`i+1`为0则边数+1
3. 左边界：如果是第0列则加1，否则判断`j-1`为0则边数+1
4. 右边界：如果是最后一列则加1，否则判断`j+1`为0则边数+1

![image.png](https://pic.leetcode-cn.com/6c38cf386fcab087ba698fdd6b0bafb0a1bdc4873c560fcf24fb739adf87779f-image.png)

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int ret = 0;
        for (int i = 0; i < grid.length; i++) {
            int[] row = grid[i];
            for (int j = 0; j < row.length; j++) {
                if(row[j] == 0) {
                    continue;
                }
                // 上
                ret += i == 0 ? 1 : (grid[i - 1][j] == 0 ? 1 : 0);
                // 下
                ret += i == grid.length - 1 ? 1 : (grid[i + 1][j] == 0 ? 1 : 0);
                // 左
                ret += j == 0 ? 1 : (grid[i][j - 1] == 0 ? 1 : 0);
                // 右
                ret += j == row.length - 1 ? 1 : (grid[i][j + 1] == 0 ? 1 : 0);
            }
        }
        return ret;
    }
}
```
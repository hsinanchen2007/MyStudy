### 解题思路
没有什么技巧，一堆一堆的放就是了
就2个步骤不断循环：
1、把一堆都放上去
2、把重叠的减去

针对第一步，先不考虑重叠，表面积应该增加 4*grid[i][j] + 2
然后考虑与上面的重叠：Math.min(grid[i-1][j], grid[i][j]) * 2
以及与左侧的交叠：Math.min(grid[i][j-1], grid[i][j]) * 2

从第一步的总面积中，扣减掉重叠面积即可

![image.png](https://pic.leetcode-cn.com/c382ea1cd4ef85d522313eb9977fbb1e2076afd1bc7033e01bf819260da6c459-image.png)


### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                result += grid[i][j] * 4 + 2;
                result -= getOverlap(grid, i, j);
            }
        }

        return result;
    }

    private int getOverlap(int[][] grid, int i, int j) {
        int overlap = 0;
        if (i != 0 && grid[i-1][j] != 0) {
            overlap += Math.min(grid[i-1][j], grid[i][j]);
        }

        if (j != 0 && grid[i][j-1] != 0) {
            overlap += Math.min(grid[i][j-1], grid[i][j]);
        }
        return overlap * 2;
    }
}
```
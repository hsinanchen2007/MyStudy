### 解题思路
把三维的空间投影到二维的空间，依次计算每个投影平面的重叠表面积。
1. 先加上每个立方体的表面积： `surfaceArea += 6 * grid[i][j];`
2. 再判断`z轴投影在x,y平面`，也就是叠放部分重叠的表面积：`surfaceArea -= 2 * (grid[i][j] - 1);`
3. 最后判断`y轴投影在z，x平面`和`x轴投影在y，z平面`的表面积。也就是想象立方体在`x，y`平面一层一层的叠放，每一层跟相邻立方体的重叠表面积： `surfaceArea -= Math.min(grid[i][j], grid[adjI][adjJ]);`

![1.jpeg](https://pic.leetcode-cn.com/83e99b06fd8efd979761a6d9cedfe04ac507b717a2be23584fe01e91376f0683-1.jpeg)
![2.jpeg](https://pic.leetcode-cn.com/f7786da4025d63af503eac99abc96773c023bc5172c6c8b75dbd5d73c39f7f42-2.jpeg)

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int surfaceArea = 0;
        int[] di = new int[] {1, -1, 0, 0};
        int[] dj = new int[] {0, 0, 1, -1};
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                // 总表面积
                surfaceArea += 6 * grid[i][j]; 
                // System.out.println(i + ", " + j + ":" + grid[i][j] + " " + surfaceArea);
                if (grid[i][j] > 0) { // 注意判断为0
                    // 减去叠放的表面积
                    surfaceArea -= 2 * (grid[i][j] - 1); 
                    // 再减去同一层的表面积
                    for (int k = 0; k < di.length; ++k) {
                        int adjI = i + di[k];
                        int adjJ = j + dj[k];
                        if (adjI < 0 || adjI >= grid.length) continue;
                        if (adjJ < 0 || adjJ >= grid[0].length) continue;
                        surfaceArea -= Math.min(grid[i][j], grid[adjI][adjJ]);
                    }
                }
            }
        }
        return surfaceArea;
    }
}
```
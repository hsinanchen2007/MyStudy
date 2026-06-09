本题的解题关键点就两个：
- 同一位置上堆叠立方体的表面积计算
- 四侧相邻立方体的重叠面积扣除

只要得知了每个位置上立方体的表面积，直接遍历数组进行面积累加，就可以轻松地得到总表面积。

### 同一位置上堆叠立方体的表面积计算
对于在位置`(i, j)`上的叠放立方体而言，它的表面积等于：
“`最底部立方体的底部面 + 最顶部立方体的顶部面 + 4个侧面 * 叠放的立方体个数`”，

即：`2 + 4 * n`, n指代该位置的叠放立方体个数。

### 四侧相邻立方体的重叠面积扣除
两个**相邻**的立方体，重叠面积的个数，必然和这两个中**最矮**的那个立方体的高度相等（因为只有这部分重叠）。即：
`Math.min(立方体1的高度， 立方体2的高度)`

故，只需要依次将这个位置的立方体与其**前后左右**四侧的立方体进行高度比较，就可以轻松得出这个立方体四周的总重叠面积。

### 代码实现

```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    // 表面积统计
    let surfaceAreaAmuont = 0;

    // 遍历，依次计算每个位置上立方体的表面积
    for(let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid.length; j++) {
            // 该位置的立方体个数
            const CubesAmount = grid[i][j];

            if (!CubesAmount) {
                // 如果这个位置不存在立方体，则跳过
                continue;
            }

            // 堆叠立方体的表面积 = 2（头部和底部的面）+ 4（每个立方体的四个侧面）* 立方体个数
            surfaceAreaAmuont += 2 + 4 * CubesAmount;

            /*
            关键点
            重叠面积的计算
            假设有两个相邻的立方体，叠放个数分别为2，5
            所以这两个立方体的重叠的个数，就是底部的那两个立方体，即2
            就可以得知对于这个位置的立方体，它有两个重叠面

            故只要依次计算出该位置立方体和其前后左右方位的立方体相互重叠的个数
            就可以计算出这个立方体的表面积
            */

            // 如果左侧有立方体
            if (i - 1 >= 0) {
                // 扣除重叠面积
                surfaceAreaAmuont -= Math.min(CubesAmount, grid[i - 1][j]);
            }
            // 如果下侧有立方体
            if (j - 1 >= 0) {
                // 扣除重叠面积
                surfaceAreaAmuont -= Math.min(CubesAmount, grid[i][j - 1]);
            }
            // 如果右侧有立方体
            if (i + 1 < grid.length) {
                // 扣除重叠面积
                surfaceAreaAmuont -= Math.min(CubesAmount, grid[i + 1][j]);
            }
            // 如果上侧有立方体
            if (j + 1 < grid.length) {
                // 扣除重叠面积
                surfaceAreaAmuont -= Math.min(CubesAmount, grid[i][j + 1]);
            }
        }
    }

    return surfaceAreaAmuont;
};
```


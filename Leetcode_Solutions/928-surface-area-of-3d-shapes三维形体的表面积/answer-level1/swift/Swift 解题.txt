### 解题思路
看了好久才看懂题意。。
- 题意
    - n*n 的网格上，输入的数组是二维数据，数组的个数是 n
    - v = grid[i][j] 代表(i, j)上放了 v 个正方体
    - 示例1：[[2]] 数组个数只有一个，代表在 1*1 的网格上，放了正方体。
        - grid[0][0] = 2，(0,0) 处放了2个正方体。
    - 示例2：[[1,2],[3,4]] 代表在 2*2 的网格上放了正方体
        - grid[0][0] = 1，(0,0) 处放了1个正方体。
        - grid[0][1] = 2，(0,1) 处放了2个正方体。
        - grid[1][0] = 3，(1,0) 处放了3个正方体
        - grid[1][1] = 4，(1,1) 处放了4个正方体
- 思路
    - 每个单元格上的正方体的 上下的面积 - 重叠面积。
    - 重叠面积 = 与 (i+1, j) 和 (i, j+1) 两处单元格的高度比较，取较矮的高度 * 2
### 代码

```swift
class Solution {
    func surfaceArea(_ grid: [[Int]]) -> Int {
        //面积
        var area = 0
        //为 n*n 的网格
        let n = grid.count
        for i in 0..<n {
            for j in 0..<n {
                if grid[i][j] > 0 {
                    //先加上上下两个方块的面积。再加上四个侧面的面积。
                    area = area + 2 + 4 * grid[i][j]
                    //需要和右侧（i+1）、前侧（j+1）来比较，减去矮的高度 * 2
                    if i+1 < n {
                        let lowH = (grid[i][j] <= grid[i+1][j] ? grid[i][j] : grid[i+1][j])
                        area = area - lowH * 2
                    }
                    if j+1 < n {
                        let lowH = (grid[i][j] <= grid[i][j+1] ? grid[i][j] : grid[i][j+1])
                        area = area - lowH * 2
                    }
                }
            }
        }
        return area
    }
}
```
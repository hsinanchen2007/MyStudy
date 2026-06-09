### 解题思路
&#160;&#160;&#160;&#160; 思路参考自官方题解下[@samperson1997](/u/samperson1997/)的评论：即统计所有“柱体”的面积，并减去相邻柱体之间重叠的面积即可。

### 代码

```cpp
/**
 * 计算全部柱体面积再减去相邻重叠面积
 *     计算每个柱体的面积，并减去相邻柱体之间重叠的面积(注意乘以2)。两柱体重叠的面积
 * 就是相邻柱体高度较低的一个柱体的高度乘以2。这样可以很好地处理“坑”的特殊情况。
 */
// Thanks: samperson1997(@leetcode.cn)
// Time: 28ms(5.83%)  Memory: 9MB(100.00%)
class Solution {
public:
    int surfaceArea(std::vector<std::vector<int>> &grid) {
        int N = grid.size(), ans = 0;
        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j) {
                int height = grid[i][j];
                if (height) // 如果有方块堆叠，计算该“柱体”的表面积
                    ans += (height << 2) + 2;
                if (i) // 减去当前柱体和上一行相邻柱体的重叠面积
                    ans -= (std::min(grid[i-1][j], height) << 1);
                if (j) // 减去当前柱体和前一列相邻柱体的重叠面积
                    ans -= (std::min(grid[i][j-1], height) << 1);
            }
        return ans;
    }
};

```
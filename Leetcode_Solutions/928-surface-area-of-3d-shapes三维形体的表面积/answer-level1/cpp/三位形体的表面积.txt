### 解题思路
最朴素的解法，遍历每个单元格，考虑每个可能影响面积的因素：如果立方体多于 1 个，总表面积先减去彼此之间贴合的面积，然后考虑上下左右是否有立方体，逐个减去遮挡的面积。最后所有的表面积相加。

之前考虑过投影，但是投影会遮挡中间的表面积。不太好考虑，遂放弃。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int len = grid.size();
        if (!len) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                int cellVal = grid[i][j];
                if (!cellVal) {
                    continue;
                }
                int area = 6 * cellVal - 2 * (cellVal - 1);
                // 左侧
                int left = i > 0 ? grid[i-1][j] : 0;
                int minV = min(cellVal, left);
                area -= minV;
                // 右侧
                int right = i < len - 1 ? grid[i + 1][j] : 0;
                minV = min(cellVal, right);
                area -= minV;
                // 上方
                int top = j > 0 ? grid[i][j - 1] : 0;
                minV = min(cellVal, top);
                area -= minV;
                // 下方
                int bottom = j < len - 1 ? grid[i][j + 1] : 0;
                minV = min(cellVal, bottom);
                area -= minV;
                ans += area;
            }
        }
        return ans;
    }
};
```
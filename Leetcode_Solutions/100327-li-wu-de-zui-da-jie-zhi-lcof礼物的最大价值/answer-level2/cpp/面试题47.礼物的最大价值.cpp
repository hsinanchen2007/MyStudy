### 解题思路
- 核心思路：动态规划，在原数组上操作，从起点到某格子路径上礼物最大价值=max(到左格最大价值,到右格最大价值)+该格礼物价值
- 执行用时：40 ms, 在所有 C++ 提交中击败了11.47%的用户
- 内存消耗：8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<grid[0].size();i++){
            grid[0][i]+=grid[0][i-1];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]=max(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
```
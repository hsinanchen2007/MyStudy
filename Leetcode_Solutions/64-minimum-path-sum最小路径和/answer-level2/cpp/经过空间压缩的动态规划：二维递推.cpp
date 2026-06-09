### 解题思路


### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    if (rowSize) {
        int columnSize = grid[0].size();
        vector<int> vc(columnSize,0);
        for (int rowIndex = 0; rowIndex != rowSize; rowIndex++) {
            for (int columnIndex = 0; columnIndex != columnSize; columnIndex++) {
                if (rowIndex == 0 && columnIndex) {
                    //当前节点的数值+横向前驱的数值
                    vc[columnIndex] = vc[columnIndex - 1] + grid[rowIndex][columnIndex];
                    continue;
                }
                if (columnIndex == 0) {
                    //当前节点纵向前驱的数值+当前节点的数值
                    vc[columnIndex] = vc[columnIndex] + grid[rowIndex][columnIndex];
                    continue;
                }
                //取纵横方向的较大者，加上当前节点的数值
                vc[columnIndex] = min(vc[columnIndex], vc[columnIndex - 1]) + grid[rowIndex][columnIndex];
            }
        }
        return vc.back();
    }
    return 0;

    }
};
```
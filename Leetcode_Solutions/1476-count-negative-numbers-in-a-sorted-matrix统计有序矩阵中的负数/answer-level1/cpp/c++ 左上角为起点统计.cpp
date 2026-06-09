### 解题思路
1. 从左上角开始，row = 0, col = grid[0].size()-1; result = 0
2. 当前值grid[row][col]为负数，则grid[row][col+i]均为负数， result += grid.size()-row；然向左移动row--
3. 当前值grid[row][col]为正数，向下移动 row++
4. 迭代重点为row >= grid.size(); 或col小于0， 返回 result
### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = 0;
        int col = grid[0].size() - 1;
        int result = 0;
        while (row < grid.size() && col >= 0) {
            if (grid[row][col] >= 0) {
                row ++;
                continue;
            } else {
                result += grid.size() - row;
                col --;
            }
        }
        return result;
    }
};
```
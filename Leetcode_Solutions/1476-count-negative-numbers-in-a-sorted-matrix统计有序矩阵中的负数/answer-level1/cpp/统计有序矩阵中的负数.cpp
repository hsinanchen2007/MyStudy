### 解题思路
关键：根据题目所给条件，找到其特性  ——>  从数组右上角出发

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(),n = grid[0].size();
        int i = 0,j = n - 1,res = 0,pivot;
        while(i < m && j >= 0){
            pivot = grid[i][j];
            if(pivot < 0) j--,res += (m - i);
            else i++;;
        }
        return res;
    }
};
```
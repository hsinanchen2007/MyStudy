### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int nCount = 0;
        for(int i = grid.size() - 1; i >= 0; i--){
            for(int j = grid[i].size() - 1; j >= 0;j--){
                if(grid[i][j] < 0){
                    nCount ++;
                }
                else{
                    break;
                }
            }
        }
        return nCount;
    }
};
```
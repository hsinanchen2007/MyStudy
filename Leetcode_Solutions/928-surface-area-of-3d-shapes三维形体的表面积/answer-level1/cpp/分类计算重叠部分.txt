### 解题思路
此处撰写解题思路
可以将重叠的部分分为三个部分，自身重叠，左侧重叠，上侧重叠；
重叠的个数为相邻的积木个数的最小值，自身重叠个数为自身个数减一；
遍历时，计算一共出现的积木数，用总的数量乘以6，再减去重叠个数乘以2即可（因为每重叠一个，会减少两个面）
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int left = 0;
        int top = 0;
        int cover = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans += grid[i][j] * 6;
                if(j> 0){
                    left = left + min(grid[i][j],grid[i][j - 1]);
                }
                if(i > 0){
                    top = top + min(grid[i][j],grid[i - 1][j]);
                }
                if(grid[i][j] > 0)
                    cover += grid[i][j] - 1;
            }
        }
        printf("%d %d %d",left,top,cover);
        ans = ans - (left + top + cover) * 2;
        return ans;
    }
};
```
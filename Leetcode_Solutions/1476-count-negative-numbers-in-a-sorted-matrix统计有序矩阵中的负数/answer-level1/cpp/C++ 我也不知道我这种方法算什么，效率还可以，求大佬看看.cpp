### 解题思路
当一个数为负数，那么这个数的右下角都为负数就不用再遍历这右下角的数了

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int r = 0;
        int c = 0;
        int ans = 0;
        while(r<R){
            c=0;
            while(c<C){
                if(grid[r][c]<0){
                    ans+= (R-r)*(C-c);
                    C=c;
                }
                c++;
            }
            r++;
        }
        return ans;
    }
};
```
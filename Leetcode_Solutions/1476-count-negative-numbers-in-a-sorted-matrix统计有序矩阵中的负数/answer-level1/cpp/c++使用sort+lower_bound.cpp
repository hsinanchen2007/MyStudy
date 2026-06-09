执行用时 :16 ms, 在所有 C++ 提交中击败了86.96%的用户

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());
            vector<int>::iterator it=lower_bound(grid[i].begin(),grid[i].end(),0);
            ans+=it-grid[i].begin();
        }
        return ans;
    }
};
```
### 解题思路
不用额外开数组，用原数组记录是否使用过

### 代码

```cpp
class Solution {
public:
    int func(vector<vector<int>>& vec,int i,int j){
        if(i<0||j<0||i>=vec.size()||j>=vec[0].size()||!vec[i][j])
        return 0;
        vec[i][j]=0;
        return 1+func(vec,i+1,j)+func(vec,i-1,j)+func(vec,i,j+1)+func(vec,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                    ans=max(ans,func(grid,i,j));
            return ans;
    }
};
```
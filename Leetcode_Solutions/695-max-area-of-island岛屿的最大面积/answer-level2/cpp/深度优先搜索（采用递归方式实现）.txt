### 解题思路
深度优先搜索（采用递归方式实现），搜索过的位置都置零，注意如果是迷宫的话，应该把走过的位置设置为其他值，以便于退回（区分）。（参考官方题解）

### 代码

```cpp
class Solution {
    int dfs(vector<vector<int>>& grid,int cur_i,int cur_j)
    {
        if(cur_i<0||cur_j<0||cur_i==grid.size()||cur_j==grid[0].size()||grid[cur_i][cur_j]==0)
        {
            return 0;
        }
        grid[cur_i][cur_j]=0;
        int ans=1;
        int di[4]={0,0,1,-1};
        int dj[4]={1,-1,0,0};
        for(int index=0;index<4;index++)
        {
            int next_i=cur_i+di[index];
            int next_j=cur_j+dj[index];
            ans+=dfs(grid,next_i,next_j);
        }
        return ans;
    }
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ans=0;
            for(int i=0;i<grid.size();i++)
                {
                    for(int j=0;j<grid[0].size();j++)
                    {
                        ans=max(ans,dfs(grid,i,j));
                    }
                }
            return ans;
        }
};
```
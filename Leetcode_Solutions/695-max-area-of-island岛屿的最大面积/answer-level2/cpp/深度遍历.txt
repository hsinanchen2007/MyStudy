### 解题思路
此处撰写解题思路
找到一个岛屿后向四周深度遍历，找到最大岛屿并记录。
### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dao=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dao=max(dao,dfs(grid,i,j));
                }
            }
        }
        return dao;
    }
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)return 0;
        grid[i][j]=0;
        int count=1;
        count+=dfs(grid,i-1,j);
        count+=dfs(grid,i+1,j);
        count+=dfs(grid,i,j-1);
        count+=dfs(grid,i,j+1);
        return count;
    }
};
```
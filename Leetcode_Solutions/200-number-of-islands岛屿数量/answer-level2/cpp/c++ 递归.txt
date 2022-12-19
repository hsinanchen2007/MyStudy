### 解题思路
题意为 在水中 连在一起的岛屿有几处(没有被水在水平垂直方向上分割开)，计算这几处的数量 
方法： 递归法，遍历所有元素，如果为0则跳过，不为0则将其连接的所有1都变为0 并 数量上加1即可

### 代码

```cpp
/* 
题意为 在水中 连在一起的岛屿有几处(没有被水在水平垂直方向上分割开)，计算这几处的数量 
方法： 递归法，遍历所有元素，如果为0则跳过，不为0则将其连接的所有1都变为0 并 数量上加1即可
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i < grid.size(); i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '0') continue;     
                ans ++;
                dfs(grid,i,j);
            }
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/75d501d2791cd6c18446e21159520358cc73ea8f5250381f664635c4ec7d3e5f-image.png)

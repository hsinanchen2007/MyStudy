### 解题思路
在做这道题目之前，希望可以先做这道题目：[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)
上面的题目是基础，把上面的做完了之后，在看这道题目，就很简单。
思路其实就两点：
- 深度优先搜索，找到联通区域
- 再原有的矩阵中去掉这些联通块
- 重复第一步，记录一共执行了多少步就可以了。

### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        hide_grid = grid;
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    if(dfs(grid,i,j)){
                        //标记执行的次数
                        count++;
                        //更新矩阵
                        grid = hide_grid;
                    };
                }
            }
        }
        return count;
    }
    //正常的bfs
    int dfs(vector<vector<char>>& grid, int c_i, int c_j){
        if(c_i < 0 || c_i == grid.size() || c_j < 0 || c_j == grid[0].size()) return 0;
        else if(grid[c_i][c_j] != '1') return 0; 
        else{
            grid[c_i][c_j] = '0';
            hide_grid[c_i][c_j] = '0';
            return 1 + dfs(grid,c_i-1,c_j) + dfs(grid,c_i+1,c_j) 
                     + dfs(grid,c_i,c_j-1) + dfs(grid,c_i,c_j+1);
        }
    }
private:
    //用于修改矩阵内的值。
    vector<vector<char>> hide_grid;
};
```
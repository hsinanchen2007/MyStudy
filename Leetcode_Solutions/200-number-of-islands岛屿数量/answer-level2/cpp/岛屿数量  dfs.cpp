### 解题思路
如果是岛屿中的一个点，并且没有被访问过就进行深度优先遍历,只对岛屿的第一个点计数

### 代码

```cpp
class Solution {
private:
    int m;
    int n;
    int count;
    
    bool inArea(int x, int y)
    {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& marked)
    {
        if (inArea(i, j) == false )//不在区域范围内、不需要再遍历
            return;
        if (marked[i][j] == 1 || grid[i][j] == '0') //已经访问过、值为0的元素不需要再遍历
            return;
        if(grid[i][j] == '1' && marked[i][j] == 0 ){
            marked[i][j] = 1;   //标记已经访问过了
            dfs(grid, i+1, j, marked);
            dfs(grid, i, j+1, marked);
            dfs(grid, i-1, j, marked);
            dfs(grid, i, j-1, marked);
        }
    }



public:
    int numIslands(vector<vector<char>>& grid) 
    { 
        m = grid.size();
        if (m < 1)
            return 0;
        n = grid[0].size();
        count = 0;

       vector<vector<int>> marked(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (marked[i][j] == 0 && grid[i][j] == '1') {  //值为1且尚未被访问
                    count ++; // 如果是岛屿中的一个点，并且没有被访问过就进行深度优先遍历,只对岛屿的第一个点计数
                    dfs(grid, i, j, marked);
                }
            }
        }
        return count;
    }


        
};
```
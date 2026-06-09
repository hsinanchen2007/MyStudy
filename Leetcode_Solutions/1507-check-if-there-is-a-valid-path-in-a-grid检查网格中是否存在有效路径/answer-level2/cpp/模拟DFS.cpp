### 解题思路
一步一步来就好了

### 代码

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis[0][0] = true;
        DFS(grid, 0, 0);
        return flag;
    }
    void DFS(vector<vector<int>>& grid, int x, int y)
    {
        if(flag)
            return ;
        if(x == n - 1 && y == m - 1)
            flag = true;
        if(grid[x][y] == 1)
        {
            int newY1 = y - 1;
            int newY2 = y + 1;
            if(newY1 >= 0 && newY1 < m && !vis[x][newY1])
            {
                if(grid[x][newY1] == 4 || grid[x][newY1] == 6 || grid[x][newY1] == 1)
                {
                    vis[x][newY1] = true;
                    DFS(grid, x, newY1);
                }
            }
            if(newY2 >= 0 && newY2 < m && !vis[x][newY2])
            {
                if(grid[x][newY2] == 3 || grid[x][newY2] == 5 || grid[x][newY2] == 1)
                {
                    vis[x][newY2] = true;
                    DFS(grid, x, newY2);
                }
            }
        }
        else if(grid[x][y] == 2)
        {
            int newX1 = x - 1;
            int newX2 = x + 1;
            if(newX1 >= 0 && newX1 < n && !vis[newX1][y])
            {
                if(grid[newX1][y] == 3 || grid[newX1][y] == 4 || grid[newX1][y] == 2)
                {
                    vis[newX1][y] = true;
                    DFS(grid, newX1, y);
                }
            }
            if(newX2 >= 0 && newX2 < n && !vis[newX2][y])
            {
                if(grid[newX2][y] == 5 || grid[newX2][y] == 6 || grid[newX2][y] == 2)
                {
                    vis[newX2][y] = true;
                    DFS(grid, newX2, y);
                }
            }
        }
        else if(grid[x][y] == 3)
        {
            int newX = x + 1;
            int newY = y - 1;
            if(newX >= 0 && newX < n && !vis[newX][y])
            {
                if(grid[newX][y] == 5 || grid[newX][y] == 6 || grid[newX][y] == 2)
                {
                    vis[newX][y]  = true;
                    DFS(grid, newX, y);
                }
            }
            if(newY >= 0 && newY < m && !vis[x][newY])
            {
                if(grid[x][newY] == 4 || grid[x][newY] == 6 || grid[x][newY] == 1)
                {
                    vis[x][newY] = true;
                    DFS(grid, x, newY);
                }
            }
        }
        else if(grid[x][y] == 4)
        {
            int newX = x + 1;
            int newY = y + 1;
            if(newX >= 0 && newX < n && !vis[newX][y])
            {
                if(grid[newX][y] == 5 || grid[newX][y] == 6 || grid[newX][y] == 2)
                {
                    vis[newX][y]  = true;
                    DFS(grid, newX, y);
                }
            }
            if(newY >= 0 && newY < m && !vis[x][newY])
            {
                if(grid[x][newY] == 3 || grid[x][newY] == 5 || grid[x][newY] == 1)
                {
                    vis[x][newY] = true;
                    DFS(grid, x, newY);
                }
            }
        }
        else if(grid[x][y] == 5)
        {
            int newX = x - 1;
            int newY = y - 1;
            if(newX >= 0 && newX < n && !vis[newX][y])
            {
                if(grid[newX][y] == 3 || grid[newX][y] == 4 || grid[newX][y] == 2)
                {
                    vis[newX][y]  = true;
                    DFS(grid, newX, y);
                }
            }
            if(newY >= 0 && newY < m && !vis[x][newY])
            {
                if(grid[x][newY] == 4 || grid[x][newY] == 6 || grid[x][newY] == 1)
                {
                    vis[x][newY] = true;
                    DFS(grid, x, newY);
                }
            }
        }
        else if(grid[x][y] == 6)
        {
            int newX = x - 1;
            int newY = y + 1;
            if(newX >= 0 && newX < n && !vis[newX][y])
            {
                if(grid[newX][y] == 3 || grid[newX][y] == 4 || grid[newX][y] == 2)
                {
                    vis[newX][y]  = true;
                    DFS(grid, newX, y);
                }
            }
            if(newY >= 0 && newY < m && !vis[x][newY])
            {
                if(grid[x][newY] == 3 || grid[x][newY] == 5 || grid[x][newY] == 1)
                {
                    vis[x][newY] = true;
                    DFS(grid, x, newY);
                }
            }
        }
    }
private:
    int n, m;
    bool vis[310][310] = {false};
    bool flag = false;
};
```
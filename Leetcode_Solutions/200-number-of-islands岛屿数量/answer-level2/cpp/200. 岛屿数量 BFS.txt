### 解题思路
先找出为‘1’的陆地，接着以它为初始节点开始bfs。
bfs中，遍历过的陆地‘1’ 修改为 水‘0’，这样可以省去用额外内存来记录是否遍历过
此外，还需要判断，初始输入的grid是否为空

### 代码

```cpp
class Solution {
public:
    typedef pair<int, int> Pint;
    queue<Pint> que;
    int m,n;
    void bfs(vector<vector<char>>& grid)
    {
        while (!que.empty())
        {
            int x,y;
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                x = que.front().first; y = que.front().second;
                // down
                if (x+1<m && grid[x+1][y] == '1')
                {
                    que.push({x+1,y});
                    grid[x+1][y] = '0';
                }
                // right
                if (y+1<n && grid[x][y+1] == '1' )
                {
                    que.push({x,y+1});
                    grid[x][y+1] = '0';
                }
                // up
                if (x-1>=0 && grid[x-1][y] == '1')
                {
                    que.push({x-1,y});
                    grid[x-1][y] = '0';
                }
                // left
                if (y-1>=0 && grid[x][y-1] == '1' )
                {
                    que.push({x,y-1});
                    grid[x][y-1] = '0';
                }
                que.pop();
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        if (!grid.size())
            return 0;
        m = grid.size(); n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    que.push({i,j});
                    bfs(grid);
                }
            }
        }

        return cnt;
    }
};
```
这题真是看得我一头雾水啊，原来想用迭代，发现人家根本就不是这么个事，结合了人家的解题，还有我渣渣的编程水平，凑合写出来了。
看懂了还是很简单的，维护了一个队列，将烂橘子位置加进去，当没有新的烂橘子过来补充队列以后 队列就慢慢空了。

### 代码

```cpp
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int num = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int len = q.size();
            {
                for(int i = 0; i < len; i++)
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    for(int j = 0; j < 4; j++)
                    {
                        int x = p.first + dx[j];
                        int y = p.second + dy[j];
                        if(x >=0 && x < m && y >= 0 && y < n && grid[x][y] == 1 )
                        {
                            grid[x][y] = 2;
                            q.push({x,y});
                        }
                    }
                }
            }
            if(!q.empty())
            {
                num ++;
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return num;
    }
};
```
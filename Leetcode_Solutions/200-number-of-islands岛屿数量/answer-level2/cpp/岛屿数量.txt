### 算法分析
1. 从左到右从上到下遍历grid，设定nums=0
2. 当grid[i][j]==1时，++nums，将pair<i, j>入队，grid[i][j]置为0
3. 遍历队列，出队pair<i, j>，判断<i,j>的四周是否存在1，如果存在则入队，并置为0
### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(min(m,n))
### 源码
```C++ []
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;
        int m = grid.size();
        
        for (int i = 0; i < m; i++)
        {
            int n = grid[i].size();
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++nums;
                    queue<pair<int, int>> arounds;
                    arounds.push(pair<int, int>(i, j));
                    grid[i][j] = '0';

                    while (!arounds.empty())
                    {
                        pair<int, int> pos = arounds.front();
                        arounds.pop();

                        int r = pos.first;
                        int c = pos.second;

                        if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        {
                            arounds.push(pair<int, int>(r - 1, c));
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < m && grid[r + 1][c] == '1')
                        {
                            arounds.push(pair<int, int>(r + 1, c));
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        {
                            arounds.push(pair<int, int>(r, c - 1));
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < n && grid[r][c + 1] == '1')
                        {
                            arounds.push(pair<int, int>(r, c + 1));
                            grid[r][c + 1] = '0';
                        }
                    }                    
                }
            }            
        }
        
        return nums;
    }
};
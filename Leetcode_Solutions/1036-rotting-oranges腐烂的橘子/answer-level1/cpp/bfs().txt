### 解题思路
此处撰写解题思路

bfs()

### 代码

```cpp
typedef pair<int,int> ipair;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<ipair> q0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2) q0.push(make_pair(i,j));
            }
        }
        queue<queue<ipair> >q;
        q.push(q0);
        while(!q.empty())
        {
            queue<ipair> top = q.front();
            q.pop();
            queue<ipair> tmp;
            while(!top.empty())
            {
                int x = top.front().first;
                int y = top.front().second;
                top.pop();
                for (int dx = -1; dx<= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (dx*dy == 0 && !(dx == 0&& dy == 0))
                        {
                            int xx = x + dx;
                            int yy = y + dy;
                            if (xx < m && xx >= 0 && yy < n && yy >= 0 && grid[xx][yy] == 1)
                            {
                                grid[xx][yy] = 2;
                                tmp.push(make_pair(xx,yy));
                            }
                        }
                    }
                }
            }
            if (!tmp.empty())ans++,q.push(tmp);
        }
        for (int i = 0;  i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) 
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
```
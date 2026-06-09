### 解题思路
BFS，对于每个坏橘子，遍历周围四个方向，将值置为2，并且将坐标放进队列，直到每个坏橘子周围没有好橘子，如果此时好橘子还有，队列就为空，返回-1，如果没有好橘子了，直接在循环中返回时间。

### 代码

```cpp
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n,m;
    int x,y;
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }else if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        if(cnt==0)return 0;
        int sz = q.size();
        int ret = 0;
        while(sz)
        {
            ret++;
            for(int i = 0; i < sz; i++)
            {
                x = q.front().first, y = q.front().second;
                //cout<<x<<"  "<<y<<endl;
                q.pop();
                for(int k = 0; k < 4; k++)
                {
                    int xx = x + dx[k], yy = y + dy[k];
                    if(xx < 0 || xx >= n || yy < 0 || yy>= m || grid[xx][yy] != 1) continue;
                    if(grid[xx][yy]==1)
                    {
                        cnt--;
                        grid[xx][yy]=2;
                        q.push(make_pair(xx,yy));
                    }
                }
                if(cnt==0) return ret;
            }
            sz = q.size();
            //cout<<"size : "<<sz<<endl;

        }
        return -1;
    }
};
```
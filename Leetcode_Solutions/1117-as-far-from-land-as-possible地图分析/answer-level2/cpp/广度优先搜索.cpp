### 解题思路
先找出所有陆地，入队列
以队首元素为对象考察四个方向，如果为海洋则与陆地距离等于当前元素值-1（陆地边缘为-1），海洋入队列，队首出队列，广度优先搜索。

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int offset[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
        int n=grid.size(),min=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1) q.push(pair(i,j));
        if(q.size() == n*n || q.size() == 0) return -1;
        while(!q.empty())
        {
            for(int i=0;i<4;i++)
            {
                int posx=q.front().first+offset[i][0];
                int posy=q.front().second+offset[i][1];
                if(0<=posx && posx<n && 0<=posy && posy<n && grid[posx][posy] == 0) 
                {
                    if(grid[q.front().first][q.front().second] == 1 ) grid[posx][posy]=-1;
                    else grid[posx][posy]=grid[q.front().first][q.front().second]-1;
                    q.push(pair(posx,posy));
                    min=min>grid[posx][posy]?grid[posx][posy]:min;
                }
            }
            q.pop();
        }
        return -min;
    }
};
```
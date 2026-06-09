### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct Node{
        int x;
        int y;
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        std::queue<Node> que;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    Node d;
                    d.x=i;
                    d.y=j;
                    que.push(d);
                }
            }
        if(que.empty()) return 0;
        int ans=0;
        Node cur,next;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        std::queue<Node>q;
        while(!que.empty())
        {
            q.push(que.front());
            que.pop();
            int sum = 0;
            while(!q.empty())
            {
                cur = q.front();
                q.pop();
                int a = cur.x;
                int b = cur.y;
                visited[a][b] = 1;
                sum++;
                for(int i = 0; i < 4; ++i)
                    {
                        int x = a + dx[i];
                        int y = b + dy[i];
                        if(x < n && x >= 0 && y < m && y >= 0 && visited[x][y] == 0 && grid[x][y] == 1)
                        {
                            next.x = x;
                            next.y = y;
                            visited[x][y] = 1;
                            q.push(next);
                        }
                    }
            }
            ans = max(ans , sum);
            //sum = 0; 
        }
        return ans;
    }
};
```
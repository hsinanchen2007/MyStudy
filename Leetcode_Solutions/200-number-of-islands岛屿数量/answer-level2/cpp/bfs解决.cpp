### 解题思路
此处撰写解题思路
使用dfs或是bfs都行，本次使用的是bfs。
### 代码

```cpp
class Solution {


public:
    void bfs(vector<vector<char>>& grid,int xx, int yy)
    {
       
       queue<pair<int, int>> q;
		q.push({ xx,yy });

        
        while(!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();
            int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int i = 0; i < 4; i++)
            {
                int dx = t.first + dir[i][0];
                int dy = t.second + dir[i][1];
                if(dx >=0 && dx < grid.size() && dy >=0 && dy < grid[0].size() && grid[dx][dy] == '1')
                {
                    pair<int, int> tt = {dx,dy};
                    q.push(tt);
                    grid[dx][dy] = '0';
                }
            }
        }
    }
public:


    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid,i,j);
                    grid[i][j] = '0';
                    ans++;
                }
            }
        }
        return ans;
    }
    
};
```
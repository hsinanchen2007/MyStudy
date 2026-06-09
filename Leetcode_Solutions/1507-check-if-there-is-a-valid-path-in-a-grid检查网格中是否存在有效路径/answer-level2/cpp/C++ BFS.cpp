### 解题思路
![1111111.jpg](https://pic.leetcode-cn.com/dfc65facec5fd0fec434d608ca3f470cddd3ddc7b32a29315a2c7948841134a6-1111111.jpg)


### 代码

```cpp
struct Point
{
    int x,y;
    int d;
    Point(int _x, int _y, int _d)
    {
        x = _x, y = _y, d = _d;
    }
};
class Solution {
    bool isOk(int cur, int next, int dir)
    {
        if(dir == 0 && (cur == 2 || cur == 5 || cur == 6) && (next == 2 || next == 3 || next == 4))
        {
            return true;
        }
        else if(dir == 1 && (cur == 1 || cur == 4 || cur == 6) && (next == 1 || next == 3 || next == 5))
        {
            return true;
        }
        else if(dir == 2 && (cur == 2 || cur == 3 || cur == 4) && (next == 2 || next == 5 || next == 6))
        {
            return true;
        }
        else if(dir == 3 && (cur == 1 || cur == 3 || cur == 5) && (next == 1 || next == 4 || next == 6))
        {
            return true;
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        queue<Point>q;
        q.push(Point(0,0,grid[0][0]));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!q.empty())
        {
            Point cur = q.front(); q.pop();
            visited[cur.x][cur.y] = true;
            if(cur.x == m-1 && cur.y == n-1)
            {
                return true;
            }
            for(int i = 0; i < 4; i++)
            {
                int nextX = cur.x + dx[i], nextY = cur.y + dy[i];
                if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY]) continue;
                
                if(isOk(cur.d, grid[nextX][nextY], i))
                {
                    q.push(Point(nextX, nextY, grid[nextX][nextY]));
                }
            }
        }
        return false;
    }
};

```
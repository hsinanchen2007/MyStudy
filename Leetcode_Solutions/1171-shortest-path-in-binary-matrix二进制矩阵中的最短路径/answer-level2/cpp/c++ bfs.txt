### 解题思路
bfs解，用dfs太麻烦


### 代码

```cpp
class Solution {
public:
    struct Node {
        int x, y;
        int step;
        Node(int _x, int _y, int _s):x(_x),y(_y),step(_s){}
    };


    int dir[8][2] = {
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {-1,0},
        {-1,-1},
        {0,-1},
        {-1,1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = (int)grid.size() - 1;
        int n = (int)grid[0].size() - 1;
        if (grid[0][0] == 1 || grid[m][n] == 1) return -1;
        if (grid[0][0] == 0 && m == 0 && n == 0) return 1;
    
        vector<int> step = {-1,0,1};
        queue<Node> que;
        que.emplace(Node(0, 0, 1));
        
        while(!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.x == m && p.y == n) return p.step;
            for (int i=0; i<8; i++) {
                int nextX = p.x+dir[i][0];
                int nextY = p.y+dir[i][1];
                if (nextX >= 0 && nextY >=0 && nextX <= m && nextY <= n && grid[nextX][nextY] == 0) {
                    que.emplace(Node(nextX, nextY, p.step+1));
                    grid[nextX][nextY] = 1;
                }
            }
        }
        return -1;
    }


};
```
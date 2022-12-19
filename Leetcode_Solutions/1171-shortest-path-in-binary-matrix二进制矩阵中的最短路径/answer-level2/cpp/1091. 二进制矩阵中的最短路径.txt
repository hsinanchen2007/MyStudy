
8方向BFS，注意起点和终点为1的情况。

```c++ []
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        bx = grid.size();
        by = grid[0].size();
        queue<shared_ptr<Node>> que;
        if(grid[0][0] || grid[bx-1][by-1]) return -1;
        que.push(make_shared<Node>(0,0,1));
        while(que.size()){
            auto now = que.front();
            que.pop();
            if(now->x == bx-1 && now->y == by-1) return now->step;
            for(int i = 0;i < 8; ++i){
                int nx = now->x + dir[i][0];
                int ny = now->y + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || grid[nx][ny])
                    continue;
                que.push(make_shared<Node>(nx, ny, now->step+1));
                grid[nx][ny] = 1;
            }
        }
        return -1;
    }
private:
    struct Node{
        int x, y;
        int step;
        Node(int _x, int _y, int _s):x(_x),y(_y),step(_s){}
    };
    int bx, by;
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
};
```
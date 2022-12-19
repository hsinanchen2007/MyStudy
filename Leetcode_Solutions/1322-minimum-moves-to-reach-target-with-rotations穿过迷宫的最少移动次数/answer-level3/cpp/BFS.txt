```
#define MAX_N 100
struct SnakeNode {
    int x;
    int y;`
    int mask;  // 0 RIGHT 1 DOWN
    int step;
    SnakeNode(int x_, int y_, int mask_, int step_){
        x = x_;
        y = y_;
        mask = mask_;
        step = step_;
    }
};

class Solution {
public:
    queue<SnakeNode> mWaitSnake;
    bool mVisited[MAX_N][MAX_N][2] = {false};
    int minimumMoves(vector<vector<int>>& grid) {
        int N = grid.size();
        SnakeNode begin(0, 0, 0, 0);
        SnakeNode curNode(0, 0, 0, 0);
        mWaitSnake.push(begin);
        while(!mWaitSnake.empty()) {
            curNode = mWaitSnake.front();
            int x = curNode.x;
            int y = curNode.y;
            int step = curNode.step;
            mWaitSnake.pop();
            // cout << "[" << x << "][" << y << "][" << curNode.mask << "] " << step << endl;
            if (x == N - 1 && y == N - 2 && curNode.mask == 0) {
                return step;
            }
            if (mVisited[x][y][curNode.mask]) {
                continue;
            }
            mVisited[x][y][curNode.mask] = true;
            // 横的情况下
            if (curNode.mask == 0) {
                // 右移一格
                if (y < N - 2 && grid[x][y + 2] != 1 && !mVisited[x][y+1][0]) {
                    SnakeNode node(x, y + 1, 0, step + 1);
                    mWaitSnake.push(node);
                }
                // 下移一格
                if (x < N - 1 && grid[x + 1][y] != 1 && grid[x + 1][y + 1] != 1
                    && !mVisited[x + 1][y][0]) {
                    SnakeNode node(x + 1, y, 0, step + 1);
                    mWaitSnake.push(node);
                }
                // 顺时针转
                if (x < N - 1 && grid[x + 1][y] != 1 && grid[x + 1][y + 1] != 1
                    && !mVisited[x][y][1]) {
                    SnakeNode node(x, y, 1, step + 1);
                    mWaitSnake.push(node);
                }
            } else {  // down  横看y，竖看x
                // 右移一格
                if (y < N - 1 && grid[x][y + 1] != 1 && grid[x + 1][ y + 1] != 1
                   && !mVisited[x][y + 1][1]) {
                    SnakeNode node(x, y + 1, 1, step + 1);
                    mWaitSnake.push(node);
                }
                // 下移一格
                if (x < N - 2 && grid[x + 2][y] != 1
                   && !mVisited[x + 1][y][1]) {
                    SnakeNode node(x + 1, y, 1, step + 1);
                    mWaitSnake.push(node);
                }
                // 逆时针转
                if (y < N - 1 && grid[x][y + 1] != 1 && grid[x + 1][y + 1] != 1
                   && !mVisited[x][y][0]) {
                    SnakeNode node(x, y, 0, step + 1);
                    mWaitSnake.push(node);
                }
            }
        }
        return -1;
    }
};
```

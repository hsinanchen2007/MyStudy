# 思路
从终点逐步往前倒推，BFS求解
```C++ []
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isValid(const vector<vector<int> >& maze, int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C && (maze[r][c] != 1);
    }
    bool canGo(const vector<vector<int> >& maze, int r, int c, int d, int nd, int R, int C) {
        int nr = r + dirs[nd][0];
        int nc = c + dirs[nd][1];
        if (!isValid(maze, nr, nc, R, C)) return false;
        if (maze[nr][nc] & (1 << (nd + 1))) return false;
        return d == nd || !isValid(maze, r - dirs[nd][0], c - dirs[nd][1], R, C);
    }
    struct Node {
        int x, y, d;
        Node(int x, int y, int d) : x(x), y(y), d(d) {};
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination) return 0;
        int dr = destination[0];
        int dc = destination[1];
        int sr = start[0];
        int sc = start[1];
        int R = maze.size();
        int C = maze[0].size();
        queue<Node> q;
        for (int i = 0; i < 4; ++i) {
            if (canGo(maze, dr, dc, -1, i, R, C)) {
                q.push(Node(dr, dc, i));
                maze[dr][dc] |= 1 << (i + 1);
            }
        }
        int step = 0;
        while (!q.empty()) {
            ++step;
            int s = q.size();
            for (int k = 0; k < s; ++k) {
                auto node = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    if (canGo(maze, node.x, node.y, node.d, i, R, C)) {
                        int r = node.x + dirs[i][0];
                        int c = node.y + dirs[i][1];
                        if (r == sr && c == sc) return step;
                        q.push(Node(r, c, i));
                        maze[r][c] |= 1 << (i + 1);
                    }
                }
            }
        }
        return -1;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a5bf5148a42c7192cc6c17fcfb120fcc8471e7006c71406230532a9417f04676-image.png)

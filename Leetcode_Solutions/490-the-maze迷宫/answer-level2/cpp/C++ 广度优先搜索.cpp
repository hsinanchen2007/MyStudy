# 思路
1，从终点开始做BFS，直到遇到起点
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
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination) return true;
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
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                if (canGo(maze, node.x, node.y, node.d, i, R, C)) {
                    int r = node.x + dirs[i][0];
                    int c = node.y + dirs[i][1];
                    if (r == sr && c == sc) return true;
                    q.push(Node(r, c, i));
                    maze[r][c] |= 1 << (i + 1);
                }
            }
        }
        return false;
    }
};
```


![image.png](https://pic.leetcode-cn.com/30210c6ec3c14d9a69e350d9eaed5ace49e611a08217e7adea57863beaf40119-image.png)

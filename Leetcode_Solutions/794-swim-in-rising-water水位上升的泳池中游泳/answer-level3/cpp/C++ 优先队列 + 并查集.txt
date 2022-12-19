```
class Solution {
public:
    struct Node {
        int x, y, h;
        Node(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {};
        bool operator < (const Node& other) const {
            return this->h > other.h;
        }
    };
    vector<int> F;
    int father(int x) {
        if (x != F[x]) F[x] = father(F[x]);
        return F[x];
    }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        F.resize(N * N);
        for (int i = 0; i < N * N; ++i) F[i] = i;
        priority_queue<Node> nodes;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                nodes.push(Node(i, j, grid[i][j]));
            }
        }
        for (int t = 0; t < N * N; ++t) {
            while (!nodes.empty() && nodes.top().h == t) {
                auto node = nodes.top();
                nodes.pop();
                int z = node.x * N + node.y;
                for (int i = 0; i < 4; ++i) {
                    int nx = node.x + dirs[i][0];
                    int ny = node.y + dirs[i][1];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] <= t) {
                        int nz = nx * N + ny;
                        F[father(nz)] = father(z);
                    }
                }
            }
            if (father(0) == father(N * N - 1)) {
                return t;
            }
        }
        return N * N - 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f34603d1a8671ace86924db14cadf2a031823515e8c14b0ea269323ec30c2d46-image.png)


从所有的建筑物出发，去做BFS
一个空点被所有的建筑物遍历到来就计算出改点到所有建筑物的距离，
取其中最小值就是解
```
class Solution {
public:
    struct Node {
        int x, y;
        Node(int _x, int _y) : x(_x), y(_y) {};
        bool operator < (const Node& other) const {
            if (x == other.x) return y < other.y;
            return x < other.x;
        }
    };
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int> > dist(R, vector<int>(C, 0));
        vector<vector<set<Node> > > mark(R, vector<set<Node> >(C));
        queue<pair<Node, Node> > q;
        int K = 0; // building count
        int E = 0; // empty place count
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) {
                    q.push({Node(i, j), Node(i, j)});
                    ++K;
                } else if (grid[i][j] == 0) {
                    ++E;
                }
            }
        }
        if (E == 0) return -1; // no empty place avaliable, return -1
        int step = 0;
        int res = INT_MAX;
        while (!q.empty()) {
            ++step;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                auto p = q.front();
                q.pop();
                auto& srcNode = p.first;
                auto& curNode = p.second;
                for (int j = 0; j < 4; ++j) {
                    int r = curNode.x + dirs[j][0];
                    int c = curNode.y + dirs[j][1];
                    if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == 0 && mark[r][c].count(srcNode) == 0) {
                        mark[r][c].insert(srcNode);
                        dist[r][c] += step;
                        if (mark[r][c].size() == K) {
                            res = min(res, dist[r][c]);
                        }
                        q.push({srcNode, Node(r, c)});
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/be8cc8f89b950c146b4d23084621c41c674fbb9135c822b0914d6d3a8de20272-image.png)

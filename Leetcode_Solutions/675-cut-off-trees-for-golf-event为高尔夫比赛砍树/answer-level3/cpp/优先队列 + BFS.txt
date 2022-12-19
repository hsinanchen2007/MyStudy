### 解题思路

思路：优先队列+BFS
1、题目的要只能从最矮的数开始砍，也就是说砍树的顺序是固定的，每次移动的起点和终点坐标也是固定的，那问题就转换为求给定两个点的最短路径
2、每次求最短路径用BFS，起点和终点怎么确定呢，可以用优先队列先存储起来所有树的位置，按照高度排序，小顶堆
3、循环出队列，记录上一次位置，每次求解pre和now之间的最短路径，累加起来即可
4、题目中所说的砍树之后高度变为1，其实没什么意义，除非题目修改为只有高度为1可以走动，但是当前题目描述的是比1大的数表示允许走过的树的高度，所以砍树之后修改值就没什么意义了

600ms 211M
--- wangtao HW-2020/3/10

### 代码

```cpp
struct Node {
        int x;
        int y;
        int high;
        int step;
        Node(int x, int y, int high, int step) : x(x), y(y), high(high), step(step) {}
        bool operator<(const Node& node) const {
            return this->high > node.high;
        }
};

class Solution {
public:
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& forest, int m, int n, Node& start, Node& end)
    {
        queue<Node> qu;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        qu.push(start);
        visited[start.x][start.y] = 1;

        while(!qu.empty()) {
            Node now = qu.front();
            qu.pop();

            if (now.x == end.x && now.y == end.y) {
                return now.step;
            }
            for (int i = 0; i < 4; i++) {
                int nx = now.x + d[i][0];
                int ny = now.y + d[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0 && visited[nx][ny] == 0) {
                    qu.push(Node(nx, ny, 0, now.step+1));
                    visited[nx][ny] = 1;
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int ans = 0;
        int m = forest.size();
        int n = forest[0].size();

        priority_queue<Node> qu;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    qu.push(Node(i, j, forest[i][j], 0));
                }
            }
        }
        Node last(0, 0, 0, 0);
        while (!qu.empty()) {
            Node now = qu.top();
            qu.pop();
            int step = bfs(forest, m, n, last, now);
            if (step == -1) return -1;
            last = now;
            ans += step;
            //forest[now.x][now.y] = 1;
        }
        return ans;
    }
};
```
这道题做了我好久才通过。自我感觉 BFS 已经很熟练了，但还是不断踩坑。

解题思路用的是最容易想到的那个：对坐标排序，然后两两算距离。算距离的办法是用 BFS.

这里再复习一下用 BFS 求两点之间距离的基本策略：

1. 如果 A == B，即刻返回 0.
2. 用一个队列 `q` 来记录下次该访问哪些（即下一“层”）。初始的时候，A 已经在里面。
3. 用 `visited` 来记录哪些已经访问过，初始的时候，所有都是 `false`，只有 A 是 `true`。
3. 用 `while (!q.empty())` 来逐层访问。
3. 用 `res` 记录当前“层”离点 A 的距离。刚开始的时候，队列中只有点 A 自己，此时的 `res` 是 0. 每次进入下一层，立刻加一。
4. 把某个元素从队列中 `pop` 并不算访问。`push` 操作才算访问。
5. 访问（`push` 元素）时，要判断是否出界，是否访问过，还有题目中的其他条件。最关键的是：如果元素与点 B 相同，那么直接返回。
6. 访问（`push`）后，要更新 `visited`。

另外在本题上发现一些现象：

1. 在 `GetDistance` 外部建好 `visited`，然后重复利用，速度会更慢，不如每次都重建。
2. 尝试在一次 BFS 时，把路过的所有点的距离都缓存下来，但速度并没有提高，反而下降。

```cpp
class Solution {
public:
    /**
    1. Sort the coordinates by value.
    2. Visit one by one, accumulate the distance.
    3. If any element's distance is negative, return -1.
    */
    int cutOffTree(vector<vector<int>>& forest) {
        // Make a sorted coordinates vector.
        vector<Coord> coords;
        int m = forest.size();
        int n = forest[0].size();
        if (m == 0 || n == 0) return -1;
        coords.reserve(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] != 0) coords.push_back({i, j});
            }
        }
        sort(
            coords.begin(), coords.end(),
            [&](const Coord& left, const Coord& right) {
                return forest[left.x][left.y] < forest[right.x][right.y];
            }
        );

        // Accumulate distance.
        int res = 0;
        Coord prevCoord = {0, 0};
        for (auto& coord : coords) {
            int dist = GetDistance(forest, prevCoord, coord);
            // printf("<%d, %d> to <%d, %d>: %d\n", prevCoord.x, prevCoord.y, coord.x, coord.y);
            if (dist == -1) return -1;
            res += dist;
            prevCoord = coord;
        }
        return res;
    }
private:
    struct Coord {
        int x;
        int y;
        bool operator==(const Coord& other) const {
            return x == other.x && y == other.y;
        }
    };
    
    // BFS from `left` until `right` appears.
    int GetDistance(const vector<vector<int>>& forest,
                    const Coord& left, const Coord& right) {
        // printf("Working on: <%d, %d> to <%d, %d>\n", left.x, left.y, right.x, right.y);
        if (left == right) return 0;

        int m = forest.size();
        int n = forest[0].size();
        
        queue<Coord> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push(left);
        visited[left.x][left.y] = true;
        
        int res = 0;
        while (!q.empty()) {
            ++res;
            // printf("\tLevel %d:\n", res);
            for (int i = q.size(); i > 0; --i) {
                Coord c = q.front();
                q.pop();
                // printf("\t\t<%d, %d>\n", c.x, c.y);
                // Push valid neighbors.
                for (int k = 0; k < 4; ++k) {
                    int x = c.x + kDirections[k];
                    int y = c.y + kDirections[k+1];
                    if (x < 0 || x >= m || y < 0 || y >= n || forest[x][y] == 0 || visited[x][y])
                        continue;
                    if (x == right.x && y == right.y)
                        return res;
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        
        return -1;
    }
    
    const vector<int> kDirections = {-1, 0, 1, 0, -1};
};
```
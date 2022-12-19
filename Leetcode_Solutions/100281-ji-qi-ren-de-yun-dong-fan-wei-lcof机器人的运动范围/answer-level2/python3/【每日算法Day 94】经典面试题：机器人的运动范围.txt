## 题解
这道题没有什么算法，比较简单，主要考察你的代码实现能力，这里我写了两个方法，一个 BFS，一个 DFS。

### BFS
BFS 的思路就是用一个队列来保存即将要访问的结点，然后不断出队，将当前结点的四周的结点满足要求的入队。为了避免重复访问，可以用一个 `vis` 数组来标记已经访问过的结点位置。

### DFS
DFS 思路就更加清晰简单了，对于一个结点来说，从它出发可以访问到的结点总数就等于从它四周的结点出发可以访问到的结点总数加一。同样需要用一个 `vis` 数组来标记已经访问过的结点位置。

## 代码
### BFS（c++）
```cpp
class Solution {
public:
    int countDigit(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        while (y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int res = 0;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        queue<pair<int, int> > Q;
        Q.push({0, 0});
        vis[0][0] = 1;
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            res++;
            int nx = p.first, ny = p.second;
            for (int i = 0; i < 4; ++i) {
                int x = nx + dx[i], y = ny + dy[i];
                if (0 <= x && x < m && 0 <= y && y < n && !vis[x][y] && countDigit(x, y) <= k) {
                    vis[x][y] = 1;
                    Q.push({x, y});
                }
            }
        }
        return res;
    }
};
```

### DFS（c++）
```cpp
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int countDigit(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        while (y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }

    int dfs(int nx, int ny, vector<vector<int> >& vis, int& m, int& n, int& k) {
        int res = 1;
        for (int i = 0; i < 4; ++i) {
            int x = nx + dx[i], y = ny + dy[i];
            if (0 <= x && x < m && 0 <= y && y < n && !vis[x][y] && countDigit(x, y) <= k) {
                vis[x][y] = 1;
                res += dfs(x, y, vis, m, n, k);
            }
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int> > vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        int res = dfs(0, 0, vis, m, n, k);
        return res;
    }
};
```

> 关注公众号【算法码上来】，每日算法干货马上就来！
![宣传图片.jpg](https://pic.leetcode-cn.com/c6407228d876c3c2862ab58e532e5aa4a1c113a848262b56bbfccf90e18ea1db-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

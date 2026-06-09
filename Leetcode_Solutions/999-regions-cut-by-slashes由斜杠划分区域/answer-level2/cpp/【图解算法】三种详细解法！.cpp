> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/f3c17f097d2e1e8cf161b4949b25603e1ab6cf88de83ae0f4faa5654a0c12890-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题解
这题如果不用写代码，直接让你数的话，那就非常简单了。但是要想实现代码，还是有点麻烦的。

最主要的麻烦点在于，如果表示出斜杠的划分？这里我提供了三种不同的方法。

### 方法 1
![6.jpg](https://pic.leetcode-cn.com/442e458bec3416d0a95f7f9ef0eef1bbe5b29f700cf9ba195488b690b2f343cb-6.jpg)

如上图所示，首先将每个格子划分成 3 x 3 的更小的网格，然后对角线上填充 1 来表示斜杠，其余地方全部填充 0 。

那么问题就转化为了求一个 3N x 3N 的网格上的 0 的连通块一共有几块，这就用普通的 dfs 搜一遍就知道了。

那么这里有个问题，为什么不能每个格子划分成 2 x 2 呢？如下图所示，这样会导致两个格子中的 0 无法只用上下左右四个方向来联通：
![9.jpg](https://pic.leetcode-cn.com/aef25e106e57aad66b561754de9a4c8d3a56b72e08063de1f798d6663436464c-9.jpg)


### 方法 2
![7.jpg](https://pic.leetcode-cn.com/ced4837226019b7b71f80845a9562abe532cfe5bf60119daa0f197f3e13f2f7a-7.jpg)

如上图所示，这种方法采用了并查集的思想。

首先将一个格子用 X 划分成四块，上图左半部分是各自之间的连通性，两个格子的相邻部分是一定连通的。

而右半部分是格子内部的连通性。如果有斜杠，那就将斜杠两边的两小块都连起来。如果没有斜杠，那就将四小块都连起来，而这只需要三条线就够了。

### 方法 3
![8.jpg](https://pic.leetcode-cn.com/445472e9819cd20965cd55a6a38aea1835a1fa4cbba38fb331e1dbf80ae37276-8.jpg)

如上图所示，这个方法还是采用了并查集的思想。这次我们不以格子为计算单元了，我们来看格点。

初始的时候，四周一圈的格点都是连通的（红色线），而内部的格点都是孤立的。这时候只有一个区域，也就是整个平面。

然后一个格子一个格子添加斜杠。首先添加绿色斜杠，也就是连接 0 和 5 格点，这时候发现这两个点不在一个连通块里，那么就没有产生区域。

然后添加蓝色斜杠，也就是连接 2 和 5 格点，这时候发现这两个点在同一个连通块里，那么就产生了一个新的区域（也就是灰色部分）。

这样遍历完所有斜杠，就能知道增加了几块新的区域了。

## 代码
### 方法 1（c++）
```cpp
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !grid[nx][ny]) {
                grid[nx][ny] = 1;
                dfs(nx, ny, grid);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> new_grid(3*n, vector<int>(3*n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    new_grid[3*i][3*j+2] = 1;
                    new_grid[3*i+1][3*j+1] = 1;
                    new_grid[3*i+2][3*j] = 1;
                } else if (grid[i][j] == '\\') {
                    new_grid[3*i][3*j] = 1;
                    new_grid[3*i+1][3*j+1] = 1;
                    new_grid[3*i+2][3*j+2] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 3*n; ++i) {
            for (int j = 0; j < 3*n; ++j) {
                if (!new_grid[i][j]) {
                    cnt++;
                    new_grid[i][j] = 1;
                    dfs(i, j, new_grid);
                }
            }
        }
        return cnt;
    }
};
```

### 方法 2（c++）
```cpp
class Solution {
public:
    vector<int> f;

    int find(int x) {
        return x==f[x] ? x : f[x]=find(f[x]);
    }

    void merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return;
        f[fv] = fu;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        f = vector<int>(4*n*n, 0);
        for (int i = 0; i < 4*n*n; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 4*(i*n+j);
                if (grid[i][j] == '/') {
                    merge(s, s+3);
                    merge(s+1, s+2);
                } else {
                    merge(s, s+1);
                    merge(s+2, s+3);
                }
                if (grid[i][j] == ' ') {
                    merge(s, s+3);
                }
                if (i > 0) merge(s, s-4*n+2);
                if (i < n-1) merge(s+2, s+4*n);
                if (j > 0) merge(s+3, s-3);
                if (j < n-1) merge(s+1, s+7);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 4*n*n; ++i) {
            if (find(i) == i) cnt++;
        }
        return cnt;
    }
};
```

### 方法 3（c++）
```cpp
class Solution {
public:
    vector<int> f;

    int find(int x) {
        return x==f[x] ? x : f[x]=find(f[x]);
    }

    int merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return 0;
        f[fv] = fu;
        return 1;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        f = vector<int>((n+1)*(n+1), 0);
        for (int i = 0; i < (n+1)*(n+1); ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            merge(i, i+1);
            merge(n*(n+1)+i, n*(n+1)+i+1);
            merge(i*(n+1), (i+1)*(n+1));
            merge(i*(n+1)+n, (i+1)*(n+1)+n);
        }
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == ' ') continue;
                int u, v;
                if (grid[i][j] == '/') {
                    u = i*(n+1)+j+1;
                    v = (i+1)*(n+1)+j;
                } else {
                    u = i*(n+1)+j;
                    v = (i+1)*(n+1)+j+1;
                }
                if (!merge(u, v)) cnt++;
            }
        }
        return cnt;
    }
};
```

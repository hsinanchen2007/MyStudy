### 解题思路
BFS，参考官方题解做的，做一些语法上的笔记
1. 初始化数组语法：int dx[4] = {1, 0, -1, 0};
2. MAX_LEN需要声明为static才能被v使用
3. struct的定义，初始化，取值方式
4. vector<vector<int>> a = grid; 将a初始化为grid的拷贝
5. memset(v, 0, sizeof(v)) 使用memset将v清零,对每个字节赋同样的值
6. queue<Coordinate> q; 初始化一个空的queue
7. queue的push、front、pop、empty方法
8. sizeof(dx) / sizeof(dx[0]) 得到数组dx的size
9. const并未区分出编译期常量和运行期常量;constexpr限定在了编译期常量
10. sizeof返回一个变量或者类型的大小（以字节为单位）

### 代码

```cpp
class Solution {
public:
    static constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_LEN = 100;

    struct Coordinate {
        int x, y, step;
    };

    bool v[MAX_LEN][MAX_LEN];
    int m, n;
    vector<vector<int>> a;
    
    int findNearestLand(int x, int y) {
        memset(v, 0, sizeof(v));
        queue<Coordinate> q;
        q.push({x, y, 0});
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
                int x1 = f.x + dx[i], y1 = f.y + dy[i];
                if (!(x1 >=0 && x1 < m && y1 >=0 && y1 < m)) continue;
                if (!v[x1][y1]) {
                    if (a[x1][y1]) return f.step + 1;
                    q.push({x1, y1, f.step + 1});
                    v[x1][y1] = 1;
                }
            }
        }

        return -1;
    }


    int maxDistance(vector<vector<int>>& grid) {
        // 使用BFS来做
        m = grid.size();
        n = grid[0].size();
        a = grid;

        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!a[i][j]) {
                    int dis = findNearestLand(i, j);
                    if (dis > ans) ans = dis;
                }
            }
        }

        return ans;
    }
};
```
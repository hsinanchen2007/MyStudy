## 思路1 动态规划
1. 将所有的坐标按照对应位置的值升序排序
2. 依次处理上一步中得到的坐标列表,从附近比当前点矮的点DP值取最大加1得到当前点的DP值、
第一步的时间复杂度是 O(log(mn))
第二步的时间复杂度是 O(mn)
```cpp
class Point {
public:
    int x, y, v;
    Point(int ix, int iy, int iv) {
        x = ix;
        y = iy;
        v = iv;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 1));
        vector<Point> vp;
        vp.reserve(rows * cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                vp.push_back(Point(i, j, matrix[i][j]));
            }
        // 对坐标排序
        sort(vp.begin(), vp.end(), [](const Point &lhs, const Point &rhs){
            return lhs.v < rhs.v;
        });
        int ret = 1;
        for (const auto &p : vp) {
            auto x = p.x;
            auto y = p.y;
            auto v = p.v;
            // 寻找附近比当前矮的点的最高DP值
            if (x > 0 && matrix[x - 1][y] < v && dp[x - 1][y] + 1 > dp[x][y])
                dp[x][y] = dp[x - 1][y] + 1;
            if (x < rows - 1 && matrix[x + 1][y] < v && dp[x + 1][y] + 1 > dp[x][y])
                dp[x][y] = dp[x + 1][y] + 1;
            if (y > 0 && matrix[x][y - 1] < v && dp[x][y - 1] + 1 > dp[x][y])
                dp[x][y] = dp[x][y - 1] + 1;
            if (y < cols - 1 && matrix[x][y + 1] < v && dp[x][y + 1] + 1 > dp[x][y])
                dp[x][y] = dp[x][y + 1] + 1;
            if (dp[x][y] > ret)
                ret = dp[x][y];
        }
        return ret;
    }
};
```
## 思路2 拓扑排序+记忆化搜索
1. 找到所有的的洼地点(即 拓扑排序中入度为0的点), 加入队列
2. 宽搜，如果搜到下一个点的路径值比当前小，则加入队列
上述两个步骤的时间复杂度均为O(mn)

```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        queue<int> qx, qy;
        const int rows = matrix.size();
        if (!rows)
            return 0;
        const int cols = matrix[0].size();
        const vector<int> dx = {1, -1, 0, 0};
        const vector<int> dy = {0, 0, 1, -1};
        vector<vector<int>> in(rows, vector<int>(cols, 0));
        vector<vector<int>> dp(rows, vector<int>(cols, 1));
        for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        for (int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[i][j] < matrix[nx][ny]) {
                in[nx][ny]++;
            }
        }
        for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (!in[i][j]) {
                qx.push(i);
                qy.push(j);
            }
        }
        int ret = 0;
        while (!qx.empty()) {
            int i = qx.front();
            int j = qy.front();
            qx.pop();
            qy.pop();
            if (dp[i][j] > ret)
                ret = dp[i][j];
            int nv = dp[i][j] + 1;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[i][j] < matrix[nx][ny]) {
                    if (dp[nx][ny] < nv)
                        dp[nx][ny] = nv;
                    in[nx][ny]--;
                    if (!in[nx][ny]) {
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
        }
        return ret;
    }
};
```
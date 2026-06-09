### 解题思路
1，大矩阵的大部分点是没有信息量的，不影响结果，因此进行坐标离散化，压缩矩阵大小
2，只需要将题目中给出的点自身且其上下左右的相邻的行列考虑在内即可，注意边界也加入其中
3，利用离散化后的小矩阵进行BFS求解

### 代码

```cpp
class Solution {
public:
    const int N = 1e6;
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int x) {
        return x >= 0 && x <= N; 
    }
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // 坐标离散化
        // 收集坐标
        vector<int> xs{0, N};
        vector<int> ys{0, N};
        for (auto& p : blocked) {
            for (int k = -1; k <= 1; ++k) {
                int x = p[0] + k;
                int y = p[1] + k;
                if (valid(x)) xs.push_back(x);
                if (valid(y)) ys.push_back(y);
            }
        }
        for (int k = -1; k <= 1; ++k) {
            int x = source[0] + k;
            int y = source[1] + k;
            if (valid(x)) xs.push_back(x);
            if (valid(y)) ys.push_back(y);
            x = target[0] + k;
            y = target[1] + k;
            if (valid(x)) xs.push_back(x);
            if (valid(y)) ys.push_back(y);
        }
        // 排序去重
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        int R = xs.size();
        int C = ys.size();
        // 离散化重新构建矩阵
        vector<vector<int> > M(R, vector<int>(C, 0));
        for (auto& p : blocked) {
            int r = lower_bound(xs.begin(), xs.end(), p[0]) - xs.begin();
            int c = lower_bound(ys.begin(), ys.end(), p[1]) - ys.begin();
            M[r][c] = -1;
        }
        int sr = lower_bound(xs.begin(), xs.end(), source[0]) - xs.begin();
        int sc = lower_bound(ys.begin(), ys.end(), source[1]) - ys.begin();
        M[sr][sc] = 1;
        int tr = lower_bound(xs.begin(), xs.end(), target[0]) - xs.begin();
        int tc = lower_bound(ys.begin(), ys.end(), target[1]) - ys.begin();
        M[tr][tc] = 2;
        // 广度优先搜索进行求解
        queue<pair<int, int> > q;
        q.push({sr, sc});
        M[sr][sc] = -1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; ++i) {
                int r = x + dirs[i][0];
                int c = y + dirs[i][1];
                if (valid(r, c, R, C) && M[r][c] != -1) {
                    if (M[r][c] == 2) return true;
                    q.push({r, c});
                    M[r][c] = -1;
                }
            }
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0dea11678916b445950522151037c7f7444291190e2d39602884e7d7a9f25256-image.png)

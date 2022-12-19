思路是：
从原点触发，一路上去找所能找到的最大值去往前走，直到最后找到重点
```
class Solution {
public:
    struct Point {
        int x, y, val;
        Point(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
        bool operator < (const Point& other) const {
            return this->val < other.val;
        }
    };
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int maximumMinimumPath(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        vector<vector<int> > visited(R, vector<int>(C, false));
        visited[0][0] = true;
        priority_queue<Point> pq;
        pq.push(Point(0, 0, A[0][0]));
        int res = min(A[0][0], A[R - 1][C - 1]);
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int r = p.x + dirs[i][0];
                int c = p.y + dirs[i][1];
                if (r >= 0 && r < R && c >= 0 && c < C && !visited[r][c]) {
                    res = min(res, p.val);
                    if (r == R - 1 && c == C - 1) return res;
                    visited[r][c] = true;
                    pq.push(Point(r, c, A[r][c]));
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ac2bad0a596b2ae5b56646a179a6a84f7db61901e9177f0b8a16728d28f550f5-image.png)

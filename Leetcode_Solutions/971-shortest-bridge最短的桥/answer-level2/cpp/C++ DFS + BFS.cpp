```
class Solution {
public:
    const int INF = 1e8;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void paint(vector<vector<int> >& A, int r, int c, int mark) {
        A[r][c] = mark;
        int R = A.size();
        int C = A[0].size();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && A[nr][nc] == 1) {
                paint(A, nr, nc, mark);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        queue<pair<int, int> > q;
        bool has_painted = false;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[i][j] > 0 && !has_painted) {
                    paint(A, i, j, 2);
                    has_painted = true;
                }
                if (A[i][j] == 1) {
                    q.push({i, j});
                    A[i][j] = -1;
                }
            }
        }
        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int k = 0; k < s; ++k) {
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirs[i][0];
                    int nc = c + dirs[i][1];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                        if (A[nr][nc] == 2) return step;
                        if (A[nr][nc] == 0) {
                            q.push({nr, nc});
                            A[nr][nc] = -1;
                        }
                    }
                }
            }
            ++step;
        }
        return step;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3a252fdfb12940c60cd0c15c58dd1433ea82e52379228efa237f4475cc222d2a-image.png)

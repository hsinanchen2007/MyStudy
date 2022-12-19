# 解法一：
**深度优先搜索DFS**
```
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isValid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    void dfs(vector<vector<int> >& A, int r, int c, int R, int C) {
        if (!isValid(r, c, R, C) || A[r][c] != 1)
            return;
        A[r][c] = -1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            dfs(A, nr, nc, R, C);
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        if (A.empty())
            return 0;
        int R = A.size();
        int C = A[0].size();
        for (int i = 0; i < R; ++i) {
            dfs(A, i, 0, R, C);
            dfs(A, i, C - 1, R, C);
        }
        for (int i = 0; i < C; ++i) {
            dfs(A, 0, i, R, C);
            dfs(A, R - 1, i, R, C);
        }
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res += A[i][j] == 1;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/b7e8faae0639334ef3ca490bdc26184c8f9c0d1507714563fde9419fdcd74ac1-image.png)

# 解法二：
**并查集**
```
class Solution {
public:
    int dirs[2][2] = {{1, 0}, {0, 1}};
    vector<int> F;
    int father(int x) {
        if (x != F[x]) F[x] = father(F[x]);
        return F[x];
    }
    bool onEdge(int x, int R, int C) {
        return x / C == 0 || x / C == (R - 1) || (x % C) == 0 || (x % C) == (C - 1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        int R = A.size();
        int C = A[0].size();
        F.resize(R * C);
        for (int i = 0; i < R * C; ++i) F[i] = i;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[i][j] != 1) continue;
                int n1 = i * C + j;
                for (int k = 0; k < 2; ++k) {
                    int r = i + dirs[k][0];
                    int c = j + dirs[k][1];
                    if (r >= 0 && r < R && c >=0 && c < C && A[r][c] == 1) {
                        int n2 = r * C + c;
                        int f1 = father(n1);
                        int f2 = father(n2);
                        if (f1 == f2) continue;
                        if (onEdge(f1, R, C)) {
                            F[f2] = f1;
                        } else {
                            F[f1] = f2;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i < R - 1; ++i) {
            for (int j = 1; j < C - 1; ++j) {
                if (A[i][j] != 1) continue;
                int f = father(i * C + j);
                if (!onEdge(f, R, C)) ++res;
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3ed9ed4e78471f7624a05ce2651cfc2f87b64a50e5885b42a66b958cc6967c03-image.png)

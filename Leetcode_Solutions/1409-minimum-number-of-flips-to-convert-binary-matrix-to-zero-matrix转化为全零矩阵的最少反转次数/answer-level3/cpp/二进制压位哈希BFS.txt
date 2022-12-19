```
class Solution {
public:
    int vis[1 << 9];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    const int INF = 0x3f3f3f3f;
    int get(int row, int col, int i, int j) {
        return i * col + j;
    }
    int minFlips(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        memset(vis, INF, sizeof(vis));
        int now = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (mat[i][j])
                    now |= (1 << get(row, col, i, j));
        queue<int> que;
        vis[now] = 0;
        que.push(now);
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            for (int i = 0; i < row; ++i)
                for (int j = 0; j < col; ++j) {
                    int nxt = top;
                    nxt ^= (1 << get(row, col, i, j));
                    for (int k = 0; k < 4; ++k) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (xx < 0 || yy < 0 || xx >= row || yy >= col) continue;
                        nxt ^= (1 << get(row, col, xx, yy));
                    }
                    if (vis[nxt] <= vis[top] + 1) continue;
                    vis[nxt] = vis[top] + 1;
                    if (nxt == 0) return vis[nxt];
                    que.push(nxt); 
                }
        }
        return vis[0] == INF ? -1 : vis[0];
    }
};
```

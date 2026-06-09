```
class Solution {
private:
    int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rtn(n, vector<int>(n, 0));
        int d = 0, x = 0, y = -1, v = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int nx = x + dir[d][0], ny = y + dir[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || rtn[nx][ny] > 0) {
                    d = (d + 1) % 4;
                    nx = x + dir[d][0];
                    ny = y + dir[d][1];
                }
                x = nx;
                y = ny;
                rtn[nx][ny] = v;
                v++;
            }
        return rtn;
    }
};
```

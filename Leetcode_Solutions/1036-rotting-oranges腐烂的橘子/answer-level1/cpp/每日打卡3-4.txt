# 思路
队列＋广度优先搜索

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<int> q;
        int cont = row * col;

        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 腐烂的橘子和空白记录为已经访问过
                if (0 == grid[i][j]) {
                    cont--;
                } else if (2 == grid[i][j]) {
                    // 腐烂橘子所在坐标入队
                    q.push(i*col + j);
                    cont--;
                } else {
                    continue;
                }
            }
        }
        if (0 == cont) return ans;
        q.push(-1);

        int i, j;
        while (true) {
            // -1作为每两次时间的间隔
            if (-1 == q.front()) {
                q.pop();
                if (q.empty() || -1 == q.front()) break;
                ans++;
                q.push(-1);
            }
            j = q.front() % col;
            i = q.front() / col;
            q.pop();
            // 将上下左右分别分析
            if (i - 1 >= 0 && 1 == grid[i - 1][j]) {
                q.push((i - 1)*col + j);
                grid[i - 1][j] = 2;
                cont--;
            }
            if (i + 1 < row && 1 == grid[i + 1][j]) {
                q.push((i + 1)*col + j);
                grid[i + 1][j] = 2;
                cont--;
            }
            if (j - 1 >= 0 && 1 == grid[i][j - 1]) {
                q.push(i*col + j - 1);
                grid[i][j - 1] = 2;
                cont--;
            }
            if (j + 1 < col && 1 == grid[i][j + 1]) {
                q.push(i*col + j + 1);
                grid[i][j + 1] = 2;
                cont--;
            }
        }
        //如果存在没有访问的，返回-1
        if (cont > 0) return -1;
        return ans;
    }
};
```
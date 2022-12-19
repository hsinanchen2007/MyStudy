### 代码

```cpp
const int stepi[5] = {-1, 0, 1, 0, -1};
const char steps[4] = {'u', 'r', 'd', 'l'};
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size();
        int m = maze[0].size();
        string res;
        int maxcnt = n * m;
        vector<vector<int>> memo(n, vector<int>(m, INT_MAX));
        vector<vector<string>> memos(n, vector<string>(m, "z"));
        deque<string> dqs{""};
        deque<vector<int>> dq{{ball[0], ball[1], -1}};
        maze[ball[0]][ball[1]] = 2;
        memo[ball[0]][ball[1]] = 0;
        memos[ball[0]][ball[1]] = "";
        while (dq.size()) {
            int x = dq[0][0];
            int y = dq[0][1];
            int dir = dq[0][2];
            int rdir = dir >= 0 ? (dir + 2) % 4 : dir;
            for (int k = 0; k < 4; k++) {
                if (k == dir || k == rdir) {
                    continue;
                }
                int dx = x + stepi[k];
                int dy = y + stepi[k + 1];
                int lcnt = memo[x][y];
                string ans = dqs[0] + steps[k];
                while (dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] != 1 && lcnt + 1 <= memo[dx][dy]) {
                    lcnt++;
                    if (dx == hole[0] && dy == hole[1]) {
                        if (lcnt < maxcnt) {
                            res = ans;
                            maxcnt = lcnt;
                        } else if (lcnt == maxcnt && res > ans) {
                            res = ans;
                        }
                        break;
                    }
                    dx += stepi[k];
                    dy += stepi[k + 1];
                }
                if (dx == hole[0] && dy == hole[1]) {
                    break;
                }
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] != 1 && lcnt >= memo[dx][dy]) {
                    continue;
                }
                dx -= stepi[k];
                dy -= stepi[k + 1];
                if (maze[dx][dy] == 0 && lcnt < maxcnt && (lcnt < memo[dx][dy] || (lcnt == memo[dx][dy] && ans < memos[dx][dy]))) {
                    memo[dx][dy] = lcnt;
                    memos[dx][dy] = ans;
                    dqs.push_back(dqs[0] + steps[k]);
                    dq.push_back({dx, dy, k});
                }
            }
            dq.pop_front();
            dqs.pop_front();
        }
        return res.empty() ? "impossible" : res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
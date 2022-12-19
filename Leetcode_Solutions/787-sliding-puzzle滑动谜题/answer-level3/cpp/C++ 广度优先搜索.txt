### 代码

```cpp
class Solution {
public:
    const int M = pow(6, 6);
    int d[5] = {0, 1, 0, -1, 0};
    int trans(const vector<vector<int> >& board) {
        int n = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                n *= 6;
                n += board[i][j];
            }
        }
        return n;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int visited[M] = {0};
        int T = 0;
        for (int i = 1; i < 6; ++i) {
            T += i * pow(6, 6 - i);
        }
        queue<int> q;
        int s = trans(board);
        if (s == T) return 0;
        q.push(s);
        visited[s] = 1;
        int step = 0;
        vector<vector<int> > b(2, vector<int>(3, 0));
        while (!q.empty()) {
            ++step;
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                s = q.front();
                q.pop();
                int x = 0;
                int y = 0;
                int t = s;
                for (int j = 0; j < 6; ++j) {
                    b[(5 - j) / 3][(5 - j) % 3] = t % 6;
                    if (t % 6 == 0) {
                        x = (5 - j) / 3;
                        y = (5 - j) % 3;
                    }
                    t /= 6;
                }
                for (int j = 0; j < 4; ++j) {
                    int x1 = x + d[j];
                    int y1 = y + d[j + 1];
                    if (x1 >= 0 && x1 < 2 && y1 >= 0 && y1 < 3) {
                        swap(b[x][y], b[x1][y1]);
                        int s1 = trans(b);
                        if (s1 == T) {
                            return step;
                        }
                        if (!visited[s1]) {
                            q.push(s1);
                            visited[s1] = 1;
                        }
                        swap(b[x][y], b[x1][y1]);
                    }
                }
            }
        }
        return -1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/65544760c527b7d3de05a1a216728f5a83fbd88c470b643e3dacc3e4e1844e90-image.png)

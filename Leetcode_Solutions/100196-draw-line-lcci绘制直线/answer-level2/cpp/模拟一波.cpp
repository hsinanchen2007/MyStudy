### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        // 00000011, 00000001 ? length * 32 = w, ?不然有啥
        int n = length * 32 / w, m = w / 32;
        vector<vector<int>> res(n, vector<int>(m, 0));
        // 0-31: board[0],  32-63: board[1], ; x: 32 * (i - 1) ~ 32 * i - 1;
        // 1. x1, x2在同一个;  x1 / 32 == x2 / 32,  [31 - x1 % 32, 31 - x2 % 32];
        // 2. x1, x2不在同一个
        // x1, board[x1 / 32][31 - x1 % 32: 0];
        // x2, board[x1 / 32][31: 31 - x2 % 32];

        // length * 32 / w = cols;
        // cols[i];   
        int t1 = x1 / 32, t2 = x2 / 32;
        if (t1 == t2) {
            for (int i = 31 - x2 % 32; i <= 31 - x1 % 32; i ++)
                res[y][t1] += 1 << i;
        } else {
            for (int i = 0; i <= 31 - x1 % 32; i ++)
                res[y][t1] += 1 << i;
            for (int i = t1 + 1; i < t2; i ++) res[y][i] = -1;
            for (int i = 31 - x2 % 32; i < 32; i ++)
                res[y][t2] += 1 << i;
        }

        vector<int> ans;
        for (auto x: res)
            for (auto y: x) ans.push_back(y);

        return ans;
    }
};
```
```
class Solution {
public:
    pair<int, int> rot(int r0, int c0, int r, int c) {
        int r1 = (r0 + c0) / 2 - c;
        int c1 = r - (r0 - c0) / 2;
        return {r1, c1};
    }
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int r0 = N - 1;
        int c0 = N - 1;
        for (int i = 0; i < (N + 1) / 2; ++i) {
            for (int j = i; j < N - i - 1; ++j) {
                int r = i;
                int c = j;
                for (int k = 0; k < 3; ++k) {
                    auto p = rot(r0, c0, r, c);
                    int nr = p.first;
                    int nc = p.second;
                    swap(matrix[r][c], matrix[nr][nc]);
                    r = nr;
                    c = nc;
                }
            }
        }
    }
};
```

![image.png](https://pic.leetcode-cn.com/21f42b4e31d9bb2cf97cfc2e586b1abaecd1f4e4555f0e1c010e18d262bb03fb-image.png)

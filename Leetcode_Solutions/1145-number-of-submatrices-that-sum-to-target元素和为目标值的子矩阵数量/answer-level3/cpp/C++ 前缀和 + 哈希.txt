```C++ []
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int> > sums(R + 1, vector<int>(C + 1, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                sums[i + 1][j + 1] = matrix[i][j] + sums[i + 1][j] + sums[i][j + 1] - sums[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = i; j < R; ++j) {
                unordered_map<int, int> m{{0, 1}};
                for (int k = 0; k < C; ++k) {
                    int s = sums[j + 1][k + 1] - sums[i][k + 1];
                    if (m.count(s - target)) {
                        res += m[s - target];
                    }
                    ++m[s];
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c35eb965e8e464f5facbce830c8986a5c8a07cfcb0ea622eb2357b78b3d5d2dd-image.png)

### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();

        int r1 = 0;
        int c1 = 0;
        int r2 = 0;
        int c2 = 0;
        int res = INT_MIN;
        for (int i = 0; i < h; ++i) {
            vector<int> dp(w, 0);//累加矩阵从第i行加到第j行
            for (int j = i; j < h; ++j) {
                int start = 0; // 每行从哪个开始求和
                int Sum = 0;// 每行求和
                for (int k = 0; k < w; ++k) {
                    if (Sum < 0) {
                        Sum = 0;
                        start = k;
                    }
                    dp[k] += matrix[j][k];
                    Sum += dp[k];
                    if (res < Sum) {
                        res = Sum;
                        r1 = i;
                        c1 = start;
                        r2 = j;
                        c2 = k;
                    }
                }
            }
        }
        return {r1, c1, r2, c2};
    }
};
```
### 解题思路
此处撰写解题思路
数组a[][]保存当前点左上角矩形之和，下标从1开始方便计算，a[i + 1][j + 1] = a[i + 1][j] + a[i][j + 1] + mat[i][j] - a[i][j]。
接着以当前点作为正方形的右下角坐标去计算所有可能的边长，如果边长已经小于ans直接break，sum=a[i + 1][j + 1] - a[i + 1][j - m + 1] - a[i - m + 1][j + 1] + a[i - m + 1][j - m + 1]

### 代码

```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int a[301][301];
        int ans = 0, m;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                a[i + 1][j + 1] = a[i + 1][j] + a[i][j + 1] + mat[i][j] - a[i][j];
                m = min(i, j) + 1;
                while (m > ans) {
                    if (a[i + 1][j + 1] - a[i + 1][j - m + 1] - a[i - m + 1][j + 1] + a[i - m + 1][j - m + 1] <= threshold) {
                        ans = m;
                        break;
                    }
                    -- m;
                }
            }
        }
        return ans;
    }
};
```
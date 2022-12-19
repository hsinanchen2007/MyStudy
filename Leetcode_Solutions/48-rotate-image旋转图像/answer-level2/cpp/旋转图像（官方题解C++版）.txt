#### 方法 1 ：转置加翻转
最直接的想法是先转置矩阵，然后翻转每一行。这个简单的方法已经能达到最优的时间复杂度$O(N^2)$。
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i < n; i++ ) {
            for (int j = i; j < n; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
- 时间复杂度：$O(N^2)$。
- 空间复杂度：$O(1)$ 由于旋转操作是 就地 完成的，并且只用了1个临时整型做辅助。 
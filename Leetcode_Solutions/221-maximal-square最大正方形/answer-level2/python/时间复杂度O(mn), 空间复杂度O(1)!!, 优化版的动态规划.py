## 解法一: 动态规划

时间复杂度：$O(mn)$
空间复杂度: $O(n)$

申请一个长度为矩阵列数的一维数组`dp`, `dp[j]`代表以`matrix[i][j]`为结尾的正方形的边长, 于是当我们计算矩阵中以某个点为右下角的正方形边长时, 就可以利用右上角已经计算过的变量直接获取相应的信息, 这里在使用`dp`时, 需要注意的一点是, 由于仅仅需要右上角的值, 因此, 每次新的`dp`生成时, 都要向后移一位, 前面补0.

```py
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0: return 0
        m = len(matrix)
        n = len(matrix[0])

        dp = [0] * (n+1)
        res = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] != '0': # 注意, 字符 '0' 在 bool 中是 True 的, 所以不能直接用 if matrix[i][j]
                    edge = dp[j]
                    k = 1
                    while (k <= edge and matrix[i-k][j]!='0' and matrix[i][j-k]!='0'): # 利用之前已经求得的正方形基础上算当前正方形边长
                        k += 1
                    dp[j] = k # 更新正方形边长
                else:
                    dp[j] = 0
                res = max(res, dp[j]) # 更新 res
            dp = [0] + dp[0:-1] # dp 数组最前方加0, 其他元素后移, 最后一个元素再后面用不到, 舍去
        return res*res
```

## 解法二: 优化的动态规划

时间复杂度：$O(mn)$
空间复杂度: $O(1)$

由于仅仅需要右上角的值, 因此我们可以把`dp`压缩到一个常数, 此时`matrix`的便利方式就不能是先行后列了, 而应该是沿着对角线进行遍历才行.

```py
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0: return 0
        m = len(matrix)
        n = len(matrix[0])

        res = 0
        i = 0
        j = 0
        while i < m or j < n:
            if i < m:
                ii = i
                jj = 0
                i += 1
            elif j < n:
                ii = 0
                jj = j
                j += 1
            dp = 0
            while ii < m and jj < n:
                if matrix[ii][jj] == '0':
                    dp = 0
                else:
                    edge = dp
                    k = 1
                    while (k <= edge and matrix[ii-k][jj] == '1' and matrix[ii][jj-k] == '1'):
                        k += 1
                    dp = k
                res = max(res, dp)
                ii += 1
                jj += 1
        return res*res
```

**C++ 实现:**
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0, i = 0, j = 0, ii = 0, jj = 0;
        while (i < m or j < n) {
            if (i < m) {
                ii = i;
                jj = 0;
                i++;
            } else if (j < n) {
                ii = 0;
                jj = j;
                j++;
            }
            int dp = 0;
            while (ii < m and jj < n) {
                if (matrix[ii][jj] == '0')
                    dp = 0;
                else {
                    int k = 1;
                    while (k <= dp and matrix[ii-k][jj] == '1' and matrix[ii][jj-k] == '1') {
                        k++;
                    }
                    dp = k;
                }
                ii++; jj++;
                res = std::max(res, dp);
            }
        }
        return res*res;
    }
};
```

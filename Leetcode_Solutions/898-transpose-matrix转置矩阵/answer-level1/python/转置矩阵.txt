#### 方法：直接复制

**思路和算法**

尺寸为 `R x C` 的矩阵 `A` 转置后会得到尺寸为 `C x R` 的矩阵 `ans`，对此有 `ans[c][r] = A[r][c]`。

让我们初始化一个新的矩阵 `ans` 来表示答案。然后，我们将酌情复制矩阵的每个条目。

```java [MYPoN2C5-Java]
class Solution {
    public int[][] transpose(int[][] A) {
        int R = A.length, C = A[0].length;
        int[][] ans = new int[C][R];
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                ans[c][r] = A[r][c];
            }
        return ans;
    }
}
```
```python [MYPoN2C5-Python]
class Solution(object):
    def transpose(self, A):
        R, C = len(A), len(A[0])
        ans = [[None] * R for _ in xrange(C)]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                ans[c][r] = val
        return ans

        #Alternative Solution:
        #return zip(*A)
```


**复杂度分析**

* 时间复杂度：$O(R * C)$，其中 $R$ 和 $C$ 是给定矩阵 `A` 的行数和列数。

* 空间复杂度：$O(R * C)$，也就是答案所使用的空间。

**测试用例：**

* 功能测试：\[\[2\], \[3,4\], \[6,5,7\], \[4,1,8,3\]\]
* 边界测试：\[\[2\]\]
* 负面测试：

## 方法：动态规划

从下图搜索的视角来看，本题存在最优子结构（节点为5时可以用最小值合并）。因此可以利用动态规划求解。

<img src='https://note.youdao.com/yws/public/resource/4e4d738cf9b51594677cedaeb48e92f3/xmlnote/WEBRESOURCE8594077048ef41be8f1128ba799d4c34/105474' width=200/>

- f(i, j)表示第i行第j个元素自顶向下的最小路径值。
- f(0, 0) = triangle(0, 0)；f(i, 0) = triangle(i, 0) + f(i-1, 0)
- 三角形以外区域都设置为inf
- f(i, j) = min(f(i-1, j-1), f(i-1, j)) + triangle(i, j)，表示当前元素的最小值等于上一两个相邻元素最小值加上本元素的值

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = [[float('inf') for j in range(n)] for i in range(n)]
        dp[0][0] = triangle[0][0]
        for i in range(1, n):
            dp[i][0] = triangle[i][0] + dp[i-1][0]
        for i in range(1, n):
            for j in range(1, i+1):
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
        return min(dp[-1])
```

**复杂度分析：**

（n表示三角形的行数）

* 时间复杂度：O(n2)
* 空间复杂度：O(n2)

## 方法2：动态规划优化

动态规划的矩阵可以优化成一维的数组，因为每次计算完第i行，除了第i-1行以外的解都没有用处了。

```python
class Solution:
    def minimumTotal(self, triangle):
        n = len(triangle)
        dp = [float('inf') for _ in range(n)]
        dp[0] = triangle[0][0]
        for i in range(1, n):
            dp_new = [0] * (i+1)
            dp_new[0] = dp[0] + triangle[i][0]
            for j in range(1, i+1):
                dp_new[j] = min(dp[j-1], dp[j]) + triangle[i][j]
            dp[:i+1] = dp_new
        return min(dp)
```

**复杂度分析：**

（n表示三角形的行数）

* 时间复杂度：O(n2)
* 空间复杂度：O(n)
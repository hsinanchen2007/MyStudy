## 思路：

我的第一个思路是用DFS,遍历所有从上到下的路径,如下图所示:

```python
def minimumTotal(self, triangle: List[List[int]]) -> int:
        self.res = float("inf")
        row = len(triangle)
        def helper(level, i, j, tmp):
            if level == row:
                self.res = min(self.res, tmp)
                return 
            if 0 <= i < len(triangle[level]):
                helper(level + 1, i, i+1, tmp + triangle[level][i])
            if 0 <= j < len(triangle[level]):
                helper(level + 1, j, j+1, tmp + triangle[level][j])
        # 层level, 访问下一层两个节点位置i,j , 目前总和tmp
        helper(0, -1, 0, 0)
        return self.res
```

上面做法遍历所有路径,所以会超时,所以我们采用**带记忆的DFS**(动态规划的自顶向下),

```python
  def minimumTotal(self, triangle) -> int:
        import functools
        row = len(triangle)

        @functools.lru_cache(None)
        def helper(level, i, j):
            if level == row:
                return 0
            res = 0
            a = float("inf")
            b = float("inf")
            if 0 <= i < len(triangle[level]):
                a = helper(level + 1, i, i + 1) + triangle[level][i]
            if 0 <= j < len(triangle[level]):
                b = helper(level + 1, j, j + 1) + triangle[level][j]
            res += min(a, b)
            return res

        return helper(0, -1, 0) 
```

接下来,我们用**自底向上动态规划**

我们先用$O(n^2)$空间,这样更容易理解

`dp[i][j]` 表示到从上到下走到`i,j`位置最小路径的值.

动态方程: `dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + triangle[i][j]`

当然对于第一个和最后一个要单独考虑.

```python
def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n == 0:
            return 0
        # 建dp空间
        dp = [[0] * i for i in range(n)]
        dp[0][0] = triangle[0][0]

        for i in range(1, n):
            for k in range(i + 1):
                if k == 0:
                    dp[i][k] = dp[i - 1][k] + triangle[i][k]
                elif k == i:
                    dp[i][k] = dp[i - 1][k - 1] + triangle[i][k]
                else:
                    dp[i][k] = min(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k]
        return min(dp[-1])
```

其实我们dp时候每次只用到上一层数据,如果我们倒着,**从底向上**可以优化成$O(n)$空间的

```python [1]
def minimumTotal(self, triangle: List[List[int]]) -> int:
        row = len(triangle)
        dp = [0] * row
        for i in range(len(triangle[-1])):
            dp[i] = triangle[-1][i]
        #print(dp)
        for i in range(row - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
        return dp[0]          
```



```java [1]
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int row = triangle.size();
        int[] dp = new int[row];
        for (int i = 0; i < row; i++) dp[i] = triangle.get(row - 1).get(i);
        for (int i = row - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
        return dp[0];
    }
}
```


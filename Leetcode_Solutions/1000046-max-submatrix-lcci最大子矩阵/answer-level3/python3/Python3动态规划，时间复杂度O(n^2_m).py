# 解题思路：
  1.对所有`(i, j),1<=i<=j<=n`，求上边为第`i`行、下边为第`j`行的最大子矩阵
      (1) 先求每一列中从第`i`到`j`行的元素总和，构成一个长度为`m`的数组，
      (2) 求该数组的最大子数组，这就是求上边为第`i`行、下边为第`j`行的最大子矩阵和
  2.遍历所有`(i, j)`，求最大值

# 复杂度分析：
  1.时间复杂度：`O(n^2*m)`
  2.空间复杂度：`O(n*m)`

# 实现代码:
```

class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        n, m = len(matrix), len(matrix[0])

        colSum = [[0] * m for i in range(n)]
        colSum[0] = matrix[0]
        for i in range(1, n):
            for j in range(0, m):
                colSum[i][j] = colSum[i-1][j] + matrix[i][j]

        ans, x1, x2, y1, y2 = -10000, -1, -1, -1, -1
        for i in range (n):
            for j in range(i, n):
                c = [colSum[j][k]-(i > 0 and colSum[i-1][k] or 0) for k in range(m)]
                d, a, b = self.maxSubarray(c)
                if d > ans:
                    ans, x1, x2, y1, y2 = d, i, j, a, b
        return [x1, y1, x2, y2]

    def maxSubarray(self, arr: List[int]) -> List[int]:
        ans, x, y = arr[0], 0, 0
        lb = [0]
        for i in range(1, len(arr)):
            if arr[i-1] > 0:
                arr[i] += arr[i-1]
                lb.append(lb[i-1])
            else:
                lb.append(i)
            if arr[i] > ans:
                ans, x, y = arr[i], lb[i], i
        return [ans, x, y]
```

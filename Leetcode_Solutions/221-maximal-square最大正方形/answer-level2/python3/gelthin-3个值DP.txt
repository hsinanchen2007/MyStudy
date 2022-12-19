### 解题思路

[以前做过的一道题，头条面试没答上来，伤心](https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/203072)

参见题解 [理解 三者取最小+1](https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/)

令 DP[i][j] 表示以 matrix[i][j]元为右下角的最大的正方形的边长，那么就有：

``` python
if matrix[i][j] == 1:
    DP[i][j] = min([DP[i-1][j], DP[i][j-1], DP[i-1][j-1]]) + 1 # 短板效应
else:
    DP[i][j] = 0
```

官方题解提供了进一步的节省存储数组的技巧。




### 代码

```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ## 难，DP 没有思路
        # 看了题解， 三个正方形，取最小的那个 + 1
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        DP = [[0]*n for _ in range(m)]
        DP[0][0] = 1 if matrix[0][0] == "1" else 0
        res = DP[0][0]

        for j in range(1, n):
            DP[0][j] = 1 if matrix[0][j] == "1" else 0
            res = max(res, DP[0][j])
        for i in range(1, m):
            DP[i][0] = 1 if matrix[i][0] == "1" else 0
            res = max(res, DP[i][0])
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == "1":
                    DP[i][j] = min([DP[i-1][j], DP[i][j-1], DP[i-1][j-1]]) + 1
                else:
                    DP[i][j] = 0
                res = max(res, DP[i][j])
        return res**2
```
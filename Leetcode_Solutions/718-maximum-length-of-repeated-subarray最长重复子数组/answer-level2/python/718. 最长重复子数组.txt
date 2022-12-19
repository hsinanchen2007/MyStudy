### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """

        """
        # 空间O(m*n)
        lenA, lenB = len(A), len(B)
        res = 0
        dp = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
        for i in range(1, lenA+1, 1):
            for j in range(1, lenB+1, 1):
                if A[i-1]==B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                res = max(res,dp[i][j])
        return res
        """

        # 空间O(m)
        lenA, lenB = len(A), len(B)
        res = 0
        dp = [0]*(lenB+1)
        for i in range(0, lenA, 1):
            for j in range(lenB-1, -1, -1):
                if A[i]==B[j]:
                    dp[j+1] = dp[j] + 1
                else:
                    dp[j+1] = 0
                res = max(res, dp[j+1])
        return res
```
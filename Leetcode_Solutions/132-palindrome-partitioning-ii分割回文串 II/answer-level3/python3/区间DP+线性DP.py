### 解题思路

两次DP

第一次区间DP，得到一个区间的字符串是不是回文串

第二次线性DP,得到[i:]区间划分的可能的最小值

时间复杂度$O(n) + O(n^2) = O(n^2)$

### 代码

```python3
class Solution:
    def minCut(self, s: str) -> int:
        l = len(s)
        dp1 = [[False] * l for _ in range(l)]  # 区间DP
        for i in range(l):
            dp1[i][i] = True
        for i in range(l - 1):
            dp1[i][i+1] = s[i] == s[i+1]
        
        for _len in range(3, l + 1):
            for i in range(l - _len + 1):
                dp1[i][i + _len - 1] = (s[i] == s[i + _len - 1] and dp1[i+1][i + _len - 2])
        
        dp2 = [float('inf')] * (l + 10)
        dp2[l] = 0
        
        for i in range(l - 1, -1, -1):  # 线性DP
            for j in range(l - 1, i -1, -1):
                if dp1[i][j]:
                    dp2[i] = min(dp2[i], dp2[j+1] + 1)
        return dp2[0] - 1
        
```
### 解题思路
直接用了编辑距离的模板。
动态规划
### 代码
```python
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        #最短编辑距离
        n,m = len(first)+1,len(second)+1
        dp = [[0]*m for i in range(n)]
        for i in range(n):
            dp[i][0] = i
        for j in range(m):
            dp[0][j] = j
        for i in range(1,n):
            for j in range(1,m):
                if first[i-1] == second[j-1]:dp[i][j] = dp[i-1][j-1]
                else:dp[i][j] = min(dp[i-1][j], dp[i-1][j-1],dp[i][j-1])+1
        return True if dp[-1][-1] <= 1 else False        
```
### 字符串切片比对
### 代码
```
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first)-len(second)) > 1:return False
        ops, lf, ls = 0, len(first), len(second)
        if lf == ls:
            for i in range(lf):
                if first[i] != second[i]:ops+=1
                if ops > 1:return False
            return True
        if lf < ls: first,second = second,first        
        for i in range(len(first)):
            if first[:i]+first[i+1:]==second:return True
        return False
```

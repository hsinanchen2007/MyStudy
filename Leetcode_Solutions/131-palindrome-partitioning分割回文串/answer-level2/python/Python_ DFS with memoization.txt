### 解题思路
此题与 [Word Break II](https://leetcode-cn.com/problems/word-break-ii/solution/dfs-with-memoization-by-dangerusswilson/) 类似， 唯一不同是这题需要检查是否是回文，Word Break II 需要检查字符串是否在字典中。

### 代码

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n, memo = len(s), {}
        
        def is_pal(s):
            return s == s[::-1]
        
        def dfs(i):
            if i in memo: return memo[i]
            if i == n: return [[]]
            lst = []
            for j in range(i+1, n+1):
                if is_pal(s[i:j]):
                    for nxt in dfs(j):
                        lst.append([s[i:j]] + nxt)
            memo[i] = lst
            return lst
        
        return dfs(0)
```
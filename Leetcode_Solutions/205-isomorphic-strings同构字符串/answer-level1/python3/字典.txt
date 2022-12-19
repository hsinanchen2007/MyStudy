### 解题思路
执行用时 :36 ms, 在所有 Python3 提交中击败了93.41%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了62.35%的用户

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        dit = {}
        n = len(s)
        for i in range(n):
            if s[i] not in dic:
                dic[s[i]] = t[i]
            elif dic[s[i]] != t[i]:
                return False
        for k in range(n):
            if t[k] not in dit:
                dit[t[k]] = s[k]
            elif dit[t[k]] != s[k]:
                return False
        return True
```
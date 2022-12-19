### 解题思路
顺序固定，判断s[i]==t[j]即可
时间复杂度O(n^2)
空间复杂度O(1)

### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        i,j = 0,0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        return i==len(s)
```
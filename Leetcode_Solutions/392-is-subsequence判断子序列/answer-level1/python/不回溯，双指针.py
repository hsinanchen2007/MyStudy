### 解题思路
不回溯，双指针

### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        m, n = len(s), len(t)
        i, j = 0, 0
        while i < m and j < n:
            # print("start: i={} j={}".format(i, j))
            if s[i] == t[j]:
                i += 1
            j += 1
            # print("over: i={} j={}".format(i, j))
        return i == m
```
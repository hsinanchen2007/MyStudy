### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        if len(s) < 3:
            return cnt
        head = 0
        tail = 2
        length = len(s)
        while tail < length:
            tmp = s[head:tail+1]
            if "a" in tmp and "b" in tmp and "c" in tmp:
                cnt += length - tail
                head += 1
            else:
                tail += 1
        return cnt
```
## 思路
每次删除掉第一次出现的连续`k`个相同的字符，

然后进行下次递归即可。

## 代码实现

```
class Solution(object):
    def removeDuplicates(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        for i in range(len(s)):
            if i + k <= len(s) and s[i:i + k] == s[i] * k:
                return self.removeDuplicates(s[:i] + s[i + k:], k)
        return s
```

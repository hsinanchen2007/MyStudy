乏善可陈。

整道题目的代码如下：

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''

        min_s = min(strs, key=len)
        res = ''
        flag = False

        for i in range(len(min_s)):
            for str in strs:
                if str[i] != min_s[i]:
                    flag = True
                    break
            if flag:
                break
            else:
                res += min_s[i]

        return res
```


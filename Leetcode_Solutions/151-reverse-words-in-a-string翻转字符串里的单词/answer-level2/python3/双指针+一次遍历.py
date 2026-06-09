从后往前遍历，通过两个指针找到所有单词的前后下标，不断存入空字符串。应该也可以用这种方法通过切片拼接在原地操作。

```
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        l = len(s)
        res = ''
        p = q = l
        for i in range(l-1, -1, -1):
            if s[i] != ' ':
                p -= 1
            elif s[p:q]:
                res += s[p:q] + ' '
                p = q = i
            else:
                p = q = i
        res += s[p:q]
        return res
```
因为s和t的长度相等，要把t变成s的异位词（即不考虑字符的顺序，只要字符出现的次数相同就行），即以s为目标，把t往s上靠。t中的字符可以分成两类：s没有的，s也有的。
1. s没有的：因为t和s的长度相等，把t中s没有的字符全都换成s中有的字符。替换的个数，就是操作数。（至此，t中全都是s中也有的字符，后续只需要替换就行）
2. s也有的：如果出现次数相等或者t中出现次数多于s中的，不用操作；如果t中某个字符的出现次数小于s中的，需要再添加的个数就是操作个数。


```
class Solution:
    def q5333_minSteps(self, s: str, t: str) -> int:
        from collections import Counter
        s_c = Counter(s)
        t_c = Counter(t)

        res = 0
        for c in s_c.keys():
            if c not in t_c.keys():
                res += s_c[c]
            elif t_c[c] < s_c[c]:
                res += s_c[c] - t_c[c]
        return res
```


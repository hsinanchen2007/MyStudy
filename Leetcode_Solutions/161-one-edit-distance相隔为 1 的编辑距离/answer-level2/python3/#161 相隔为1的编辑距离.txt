### 解题思路
假设s的长度永远小于等于t。
先判断简单的停止条件：
1. s、t都空或者s和t相同，距离为0，返回false
2. 两个字符串的长度差大于1，编辑距离肯定大于1，返回false

剩下的有两种情况：
情况1： s和t长度相等
情况2： s和t长度差1

循环遍历两个字符串，比较同一位置的字符，如果相同则往后继续遍历，如果不同分情况处理：
1. 对于情况1，两个字符串当前位置后面的子串必须相同。
2. 对于情况2，t在当前位置后的字串必须和s从当前位置起的字串相同。

遍历结束后，只能是s和t长度差1，且t除最后一个字符以前的字串和s相同，此时编辑距离一定为1。

*此处的s[i+1:]和t[i+1]不会引起数组越界，就算i是最后一个位置，因为python对切片的定义（见下）。

### 代码

```python3
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if not s and not t or s == t:
            return False
        
        if len(s) > len(t):
            return self.isOneEditDistance(t, s)

        if len(t) - len(s) > 1:
            return False

        for i in range(len(s)):
            if s[i] == t[i]:
                continue
            if len(s) == len(t):
                return s[i + 1:] == t[i + 1:]
            return t[i + 1:] == s[i:]
        return True
```

### Python3 slicing
s[i:j]

The slice of s from i to j is defined as the sequence of items with index k such that i <= k < j.
If i or j is greater than len(s), use len(s).
If i is omitted or None, use 0.
If j is omitted or None, use len(s).
If i is greater than or equal to j, the slice is empty.

文档：[sequence-types-list-tuple-range](https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range)
源码：[stringobject.c](https://svn.python.org/projects/python/trunk/Objects/stringobject.c)
参考：[link](https://segmentfault.com/q/1010000011412371)
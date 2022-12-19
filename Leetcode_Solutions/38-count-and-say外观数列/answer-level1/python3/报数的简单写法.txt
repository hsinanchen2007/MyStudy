看题看了半天，然后想到了一个很基础的方法
```
class Solution:
    def countAndSay(self, n: int) -> str:
        s, i = '1', 1
        while i < n:
            temp, i, Sum = '', i + 1, 0
            pre, cur = 0, 0
            while cur < len(s):
                if s[pre] == s[cur]:
                    Sum, cur = Sum + 1, cur + 1
                else:
                    temp = temp + '{}{}'.format(Sum, s[pre])
                    pre, Sum = cur, 0
                if cur == len(s):
                    temp = temp + '{}{}'.format(Sum, s[pre])
            s = temp
        return s
```

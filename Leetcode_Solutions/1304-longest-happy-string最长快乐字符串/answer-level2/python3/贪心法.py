## 解题思路

贪心法，每次选剩下的较多的那个，但是需要判断选择了当前这个之后，剩下的字符是比自己多还是少，如果多的话，就放一个，否则放两个

时间复杂度`O(max(a, b, c))`
空间复杂度`O(1)`


## 代码

```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = ""
        m = max(a, b, c)
        if (a + b + c) - m >= m:
            aaa = 1
        else:
            aaa = 2
        if m == a:
            res += "a" * min(m ,aaa)
            lt = "a"
            a -= min(m ,aaa)
        elif m == b:
            res += 'b' * min(m ,aaa)
            lt = "b"
            b -= min(m ,aaa)
        else:
            res += 'c' * min(m ,aaa)
            lt = "c"
            c -= min(m ,aaa)
        while True:
            if lt == 'a':
                m = max(b, c)
                if (a + b + c) - m >= m:
                    aaa = 1
                else:
                    aaa = 2
                if m == 0:
                    return res
                else:
                    if m == b:
                        res += "b" * min(m, aaa)
                        b -= min(m ,aaa)
                        lt = "b"
                    else:
                        res += "c" * min(m, aaa)
                        c -= min(m, aaa)
                        lt = "c"
            elif lt == 'b':
                m = max(a, c)
                if (a + b + c) - m >= m:
                    aaa = 1
                else:
                    aaa = 2
                if m == 0:
                    return res
                else:
                    if m == a:
                        res += "a" * min(m, aaa)
                        a -= min(m ,aaa)
                        lt = "a"
                    else:
                        res += "c" * min(m, aaa)
                        c -= min(m, aaa)
                        lt = "c"
            else:
                m = max(b, a)
                if (a + b + c) - m >= m:
                    aaa = 1
                else:
                    aaa = 2
                if m == 0:
                    return res
                else:
                    if m == b:
                        res += "b" * min(m, aaa)
                        b -= min(m ,aaa)
                        lt = "b"
                    else:
                        res += "a" * min(m, aaa)
                        a -= min(m, aaa)
                        lt = "a"
```
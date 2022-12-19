本题不需要记录每个每个char出现的次数。
bits记录该字符unicode是否出现。
首先遍历字符串，计算每个字符unicode码：
1.如果unicode在bits上已经出现（bits & mask is True）则res+=2,然后bits这位置空（bits ^= mask）
2.如果unicode在bits上是0（bits & mask is False），则bits此位置为1（bits |= mask），表示出现过
```
class Solution:
    def longestPalindrome(self, s: str) -> int:
        res = bits = 0
        for w in s:
            mask = 1 << ord(w)
            if bits & mask:
                bits ^= mask
                res += 2
            else:
                bits |= mask
        return res+1 if bits else res
```

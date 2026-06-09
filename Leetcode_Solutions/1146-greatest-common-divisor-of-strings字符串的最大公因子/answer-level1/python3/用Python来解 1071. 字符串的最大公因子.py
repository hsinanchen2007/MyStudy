### 解题思路
解题思路，先考虑最长 X 存在的必要条件：
1. 字符集需要一致。比如，如果有一个字符只存在于str1或str2中，则X不可能存在
2. 两个字符串的长度存在最大公约数，否则也不能除尽

如何确定X，X的最大长度不可能大于字符串长度的最大公约数。


### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        
        # 判断字符集
        if set(str1) != set(str2):
            return ""

        # 任意为空
        if not str1 or not str2:
            return ""

        if len(str1) > len(str2):
            l, s = str1, str2
        else:
            l, s = str2, str1
        
        
        # 求最大公约字符串的最大可能长度，以下是最大公约数的经典算法
        def divisor(p, q):
            tmp = p % q
            while tmp != 0:
                p = q
                q = tmp
                tmp = p % q
            return q
        
        # 验证str1, str2 可以被 sub 字符串除尽
        def verify(str1, str2, sub):
            return (str1.replace(sub, "") == "" and str2.replace(sub, "") == "")

        ret = tmp = ""
        divisorlength = divisor(len(l), len(s))

        # 长度最大公约数为 1 时
        if divisorlength == 1 and verify(s, l, str1[0]):
            return ret

        index = divisorlength 
        while index > 0:
            tmp = s[:index]
            if verify(s, l, tmp):
                ret = tmp
                break
            else:
                index -= 1
        
        return ret
```
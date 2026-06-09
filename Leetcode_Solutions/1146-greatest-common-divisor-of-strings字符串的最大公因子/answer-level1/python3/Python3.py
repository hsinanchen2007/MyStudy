### 解题思路
如果以两个字符串长度的最大公约数为长度的子串作为T, 不能满足要求的话, 更短的T也不可能, 直接返回""

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def gcd(a, b):
            while b != 0:
                a, b = b, a % b
            return a

        m, n = len(str1), len(str2)
        if not m or not n:
            return ""
        l = gcd(m, n)
        if str1[:l]*(m//l) == str1 and str2[:l]*(n//l) == str2 and str1[:l]==str2[:l]:
            return str1[:l]
        else:
            return ""
```
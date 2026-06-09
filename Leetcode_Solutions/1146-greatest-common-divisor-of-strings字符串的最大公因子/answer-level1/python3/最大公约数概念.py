### 解题思路
此处撰写解题思路
1. 证明最大公约数（K）与最大公约串（S）的关系
2. 反证法：需要注意点，最大公约数组成的字符串也是公约串（需要被两个字符串整约）
3.     如果K > len(S)，则K组成的字符串是公约串，此时S就不是最大公约串
4.     如果K < len(S)，此时K组成的公约串，小于S，不是最大公约串。则K还可以更大
### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        def gcd(m, n):
            if n == 0:
                return m
            # print(m, n,m%n)
            return gcd(n, m%n)
        return str1[:gcd(len(str1), len(str2))]
```
执行用时 :44 ms, 在所有 Python3 提交中击败了95.96% 的用户。
内存消耗 :13 MB, 在所有 Python3 提交中击败了96.10%的用。

类似于进制转换，通过不断的短除取余得到每个位上的字母

```
class Solution:
    def convertToTitle(self, n: int) -> str: 
        if n<=0: 
            return None 
        numA=ord("A") 
        res = ''
        while n // 26 > 0:
            res = chr((n-1)%26 + numA) + res
            n = (n-1) // 26
        if n != 0:
            res = chr(n-1+numA) + res
        return res
```
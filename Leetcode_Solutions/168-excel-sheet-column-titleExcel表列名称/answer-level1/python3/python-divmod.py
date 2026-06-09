```
class Solution:
    def convertToTitle(self, n: int) -> str:
        #python divmod() 函数把除数和余数运算结果结合起来，返回一个包含商和余数的元组(a // b, a % b)
        #chr() 用一个范围在 range（256）内的（就是0～255）整数作参数，返回一个对应的字符
        res=""
        while n:
            n,y = divmod(n,26)
            if y==0:
                n-=1
                y = 26
            res = chr(y+64)
        return res
```

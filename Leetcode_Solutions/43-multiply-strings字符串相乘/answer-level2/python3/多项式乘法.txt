```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1 = len(num1)
        len2 = len(num2)
        result = 0
        for i in num1:
            i = int(i) * (10**(len1-1))
            len2 = len(num2)
            for j in num2:
                j = int(j) * (10**(len2-1))
                result += i * j
                len2 -= 1
            len1 -= 1
        
        return str(result)
```
思路比较简单，效率也不怎么高哈哈哈哈
总之就是多项式乘法。
552 * 325
(500+50+2)*(300+20+5)
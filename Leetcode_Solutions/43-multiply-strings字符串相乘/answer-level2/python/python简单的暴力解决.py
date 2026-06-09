两层循环，乘法的基本原理
```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num1 = num1[::-1]
        num2 = num2[::-1]
        
        s = 0
        for i in range(0,len(num2)):
            cur = 0
            for j in range(0,len(num1)):
                cur += int(num2[i])*int(num1[j])*pow(10,j)
            s += cur*pow(10,i)
        return str(s)
```
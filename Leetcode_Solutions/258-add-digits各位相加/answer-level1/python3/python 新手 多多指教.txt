### 代码
```python3
class Solution:
    def addDigits(self, num: int) -> int:
        while len(str(num))!=1:
            num2=0
            for i in str(num):
                i=int(i)
                num2=num2+i
            num=num2
        return num
```
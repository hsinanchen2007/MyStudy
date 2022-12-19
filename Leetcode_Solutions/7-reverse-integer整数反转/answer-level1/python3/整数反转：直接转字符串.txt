
1. 判断正负
2. 若负，保留符号，并转正
3. 转字符串
4. 反转字符串
5. 转整数
6. 放符号
7. 检查是否溢出



```python []
class Solution:
    def reverse(self, x: int) -> int:
        isF = True
        if x<0:
            isF = False
            x=x*-1
        xS = str(x)[::-1]
        x = int(str(x)[::-1])
        if not isF:
            x=x*-1
        if x<-2**31 or x>2**31-1:
            return 0
        return x
```


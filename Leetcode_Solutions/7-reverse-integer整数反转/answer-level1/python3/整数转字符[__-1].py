1. 考虑当前整数是正数还是负数
2. 将整数转换成字符串进行反转
3. 判断值是否有溢出

```python
class Solution:
    def reverse(self, x: int) -> int:
        flag = False
        if x < 0:
            flag = True
            x = abs(x)
        reversex = int(str(x)[::-1])
        if flag:
            reversex *= -1

        if not (-1*(2**31) <= reversex <= (2**31)-1):
            return 0
        return reversex
```
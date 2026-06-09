### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        x = num
        while x * x > num:
            x = int(x-(x*x-num)/(2*x))
        return x * x == num
```
rt 令x=int() 里面的式子的时候是通过不了的，由于x是递减的，故用向下取整int可行。
欢迎指点呀
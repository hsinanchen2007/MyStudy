```
class Solution:
    def reverse(self, x: int) -> int:
        if x>=0:
            res = int(str(x)[::-1])
            res = res if pow(2, 31) - 1 >= res >= pow(-2, 31) else 0
            return res 
        else:
            res = int(str(-x)[::-1]) * -1 
            res = res if pow(2, 31) - 1 >= res >= pow(-2, 31) else 0
            return res
```
时间复杂度On,空间复杂度O1

1. python不存在整数溢出，仅最后添加判断输出0即可
2. 如需考虑溢出问题，提前添加判断即可

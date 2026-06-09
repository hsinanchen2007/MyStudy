思路一：BFS(超时)

思路二：
可以将此问题看做是以下问题：
给定一个数组为1,2,3,4,5.......i，为数组元素添加正负号（正号表示向右跳，负号表示向左跳），使得其和为target的最小数组长度
记录数组添加正号数字之和为p, 添加负号数字之和为n，数组之和为s
p + n = s
p - n = target
两式相减有：
s - target = 2 * n
**因此s - target一定为偶数，且s - target  = 2 * n >= 0**
而s = i *(i + 1) /2
因此就是求最小的i， 使得 i *(i + 1) /2 - target为偶数且大于等于0
```
class Solution:
    def reachNumber(self, target: int) -> int:
        if target < 0:
            target = -target
        i = 1
        while True:
            s = (i * i + i ) // 2
            if s >= target and (s - target) % 2 == 0:
                return i
            i += 1
```




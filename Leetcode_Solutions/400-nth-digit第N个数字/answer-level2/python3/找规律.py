规律
（1）所有i位数的数字和为 9 * 10 **（i-1） * i
实现
```
class Solution:
    def findNthDigit(self, n: int) -> int:
        i = 0
        count = 0
        while count < n:
            i += 1
            count += 9 * 10**(i - 1) * i
        s = (count - n) // i + 1    # 多余数的个数
        y = (count - n) % i + 1     # 定位数字的位置

        return int(str(10**i - s)[-y])
```

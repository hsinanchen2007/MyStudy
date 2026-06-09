![image.png](https://pic.leetcode-cn.com/9f2ad39a1f323d0690cfe9b7e7b56f9a08f04dfdee752a71c329a0f0191da04a-image.png)


```
from functools import lru_cache

class Solution:

    lru_cache(typed = False)
    def countDigitOne(self, n: int) -> int:
        # # dp[i] 表示i位数包含多少个1, 先计算出来，然后直接查表

        # dp = [0 for _ in range(12)]
        # dp[1] = 1
        # for i in range(2, 12):
        #     dp[i] = int(10**(i-1)) + 9 * sum(dp[:i])
        #
        # print(dp)

        if n <= 0:
            return 0

        if n <= 9:
            return 1

        dp = [0, 1, 19, 280, 3700, 46000, 550000, 6400000, 73000000, 820000000, 9100000000, 100000000000]
        for i in range(1, len(dp)):
            dp[i] = dp[i] + dp[i-1]

        base, i = 1, 0
        while base <= n:
            base *= 10
            i += 1
        bits = i
        base //= 10

        # 最高位数字
        high_bit = n // base
        ans = 0

        # 最高位是1的数字中最高位的1出现总次数
        if high_bit != 1:
            ans += int(10 ** (bits - 1))
        else:
            ans += (n % base + 1)

        # 最高位是1到最高位是high-bit-1的数值中非最高位1出现总次数
        for i in range(1, high_bit):
            ans += dp[bits - 1]

        # 最高位和n的最高位相等的数字中非最高位1出现的总次数
        ans += self.countDigitOne(n % base)

        # 最高位是0的数值中1出现总次数
        ans += dp[bits-1]

        return ans
```

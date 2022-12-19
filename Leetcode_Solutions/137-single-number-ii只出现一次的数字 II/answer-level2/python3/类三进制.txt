1. 空间复杂度o(1)，时间复杂度o(n)
2. 数字转3进制，随便定义一种操作@只需满足：A@A@A = 0,0@A=A,并且满足交换律
3. 这里把正数和负数分开操作了。
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dp = [0] * 20
        np = [0] * 20
        for num in nums:
            i = 0
            if num > 0:
                while num != 0:
                    dp[i] += num % 3
                    num = num // 3
                    i += 1
            if num < 0:
                num = -num
                while num != 0:
                    np[i] += num % 3
                    num = num // 3
                    i += 1
        #正数   
        p = 0
        b = 1
        for i in dp:
            p += b * (i%3)
            b = 3 * b
        #负数
        n = 0
        b = 1
        for i in np:
            n += b * (i%3)
            b = 3 * b
        
        if p > 0:
            return p
        elif n > 0:
            return -n
        else:
            return 0
```

思路是一样的，但是官方的归纳能力和写法真心比不了
1. 自己的代码
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        if n == 1: return "1"

        nums = [i for i in range(1, n + 1)]
        res = ""

        while k > 0 or n > 1:
            fac = math.factorial(n - 1)
            di, re = k // fac, k % fac

            if re == 0 and di != 0:
                res += str(nums[di-1])
                nums = nums[:di-1] + nums[di + 1 - 1:]
            elif re == 0 and di == 0:
                res += str(nums[-1])
                nums = nums[:-1]
            else:
                res += str(nums[di])
                nums = nums[:di] + nums[di + 1:]
            n -= 1
            k = re

        res += str(nums[0])

        return res
```

循环计算每个数字的位数，然后判断位数是否为偶数。
```
class Solution(object):
    def findNumbers(self, nums):
        count = 0
        for i in range(len(nums)):
            n = 0            
            while nums[i] > 0:
                nums[i] //= 10
                n += 1
            if n % 2 == 0:
                count += 1
        return count
```

```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        '''
        数字有可能有负数
        由于是三个数的最大乘积，所以就符号而言，有三种情况：
        （1） 三个均为正
        （2） 一个正，两个负
        （3）如果数字全部为负
        '''
        nums = sorted(nums)
        if nums[-1] <= 0 :
            return nums[-1]*nums[-2]*nums[-3]
        else:
            return max(nums[0]*nums[1]*nums[-1],nums[-1]*nums[-2]*nums[-3])
```
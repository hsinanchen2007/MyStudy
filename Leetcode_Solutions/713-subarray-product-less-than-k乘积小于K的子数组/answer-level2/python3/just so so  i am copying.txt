```
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int: 
        # 由于是连续的子数组
        # 所以可以通过两个指针，即滑动窗口去框处小于k的区间，知道遍历完为止
        # 再右指针移动的过程中，进行计算组合有多少个
        # 因为必须是连续的数组，他的组合次数，其实符合斐波那契堆的，就是逐渐累积
        # 因此代码逻辑如下：
        res,s = 0, 1
        left, right = 0,0
        while(right < len(nums) and left < len(nums)):
            if s*nums[right] < k:
                res += right-left + 1
                s *= nums[right]
                right += 1
            else:
                s /= nums[left]
                left += 1
        return res



```

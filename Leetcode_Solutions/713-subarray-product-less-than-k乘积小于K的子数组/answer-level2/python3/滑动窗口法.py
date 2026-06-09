一 算法思想
滑动窗口法属于双指针法的一种，可用于一些查找满足一定条件的连续区间的问题。一般设置两个指针left、right分别表示连续区间的左、右端点，初始时一般将left、right指向原数组初始位置。当left、right发生变化时（如逐渐向右移动），可通过原来的计算结果计算新区间的结果，从而减少运算量。
该题目为找出数组内乘积小于k的连续子数组个数，可以利用滑动窗口法。具体算法如下：
1 当k<=1时，由于数组为正整数数组，明显不存在满足题意的连续子数组，故直接返回结果0。
2 令保存结果的变量res=0，滑动区间左指针left=0，保存滑动区间中元素乘积的变量pro为1。
3 令滑动区间右指针right从数组左到右滑动，每滑动1次，让pro乘以新元素。如果此时pro大于等于k，则滑动左指针left,每滑动一次令pro除以nums[left]，得到新的滑动区间的元素乘积，直到pro<k。此时，以right为右边界，以滑动区间中任一元素为左边界的子数组都满足题意。由此可以得到以right为子数组右边界的所有子树组的个数right-left+1，将改数值累加至结果res。
4 当right滑动到最右端后，res中便累加了以各个元素为子数组右端点时的有效子数组个数。返回res即可。
二 算法实现
```
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        
        res = 0
        left = 0
        pro = 1
        N = len(nums)
        for right in range(N):
            pro *= nums[right]
            while pro >= k:
                pro /= nums[left]
                left += 1
            res += right - left + 1
        return res
```
三 算法复杂度
时间复杂度：O(N)。虽然算法中有两重循环，但由于left和right都只是从左到右遍历一次，故算法的时间复杂度为O(N)。
空间复杂度：O(1)。算法中只用了几个变量，故空间复杂度为O(1)。
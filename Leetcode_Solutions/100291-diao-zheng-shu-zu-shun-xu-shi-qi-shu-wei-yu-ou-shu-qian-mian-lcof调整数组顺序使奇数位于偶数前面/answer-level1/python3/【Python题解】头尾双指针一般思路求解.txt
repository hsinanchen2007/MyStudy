# 头尾双指针滚动

设置两个指针于头、尾索引处，**主体思路是两个指针同时往中心收缩，在收缩过程中逐渐使数组符合题目要求**。

主体大循环的条件只需要是左指针小于右指针即可，
在大循环的内部令头指针一直左移直到碰到第一个偶数停下；同理：尾指针一直右移直到碰到第一个奇数停下；
然后做判断，只有当左指针索引小于右指针索引的时候才做数组元素的交换（防止无用交换）。
交换完成后，左右指针同时收缩，再回到大循环条件处。

值得留心的地方是在**交换和收缩的过程中要时刻留意头尾指针的数值，小心索引越界了**。

代码：
```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        lens = len(nums)-1
        left = 0
        right = lens
        while left < right:
            while nums[left]%2 != 0 and left<lens:
                left+=1
            while nums[right]%2 == 0 and right>0:
                right-=1
            if left<right :
                nums[left],nums[right] = nums[right],nums[left]
                left+=1
                right-=1
        return nums
```
从空间和时间复杂度来看，应该算是性能较为不错的解法。

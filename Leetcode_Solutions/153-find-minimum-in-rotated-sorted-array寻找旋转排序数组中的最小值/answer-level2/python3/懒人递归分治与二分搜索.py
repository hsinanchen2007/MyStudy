直观来看，本题可以使用O(n)的时间复杂度来找到最小值，能否在进一步优化时间复杂度？

在有序数组中，可以直接找到最小值，例如[1,2,3,4,5]，可以直接知道min=1即最左侧的元素。
那么同理对于旋转有序数组来说，也可以将其分为两份，如[3,4,5,1,2]，可以取min= min([3,4,5], [1,2]) = 1。
这个思路的关键在于如何将数组划分为有序数组。

考虑将数组一分为二，那么数组的旋转点可能位于中间点、左区间、右区间，也就是说至少一个区间是一定有序的。
```
中右侧有序：
a. [4,0,1,2,3]
b. [4,5,1,2,3]

左侧有序：
c. [4,5,6,1,2]
```

从情况a可以看到，最小值可能出现在无序区间中。最直观暴力的方法是，**把数组中所有有序区间的最小值都拉出来比较，那肯定也可以得出整体最小值**, 问题也就变成了找到数组中的所有有序区间。

在二分的情况下，可能会出现一个无序区间，如果出现无序区间，可以继续进行二分，直到分成有序区间，这也就符合递归的定义。

但为什么说是**懒人递归**呢？因为以上的直观解法就属于暴力的一种。

献出代码来展示递归可以有多懒，可以看到几乎无需复杂的条件判断，并且时间复杂度也是O(logn)。
```
class Solution:
    def findMin(self, nums: [int]) -> int:
        def search_min(left, right):
            # 有序下直接返回最小值nums[left]
            if nums[right] >= nums[left]:
                return nums[left]
            else:
                mid = (left + right) >> 1
                # 无序的情况下，反转点可能在左侧区间或右侧区间
                # [4,0,1,2,3], [4,5,1,2,3], [4,5,6,1,2]
                return min(search_min(left, mid), search_min(mid+1, right))
        
        return search_min(0, len(nums) - 1)
```
在这种方式下，稍加一点条件考虑即可秒杀[
154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)



如果需要继续优化，则需要进行额外的条件判断避免像递归一样枚举所有有序区间。
```
class Solution:
    def findMin(self, nums: [int]) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            if nums[left] <= nums[right]:
                return nums[left]

            mid = (left + right) >> 1
            # 右边有序时，往左边查找可能的最小值
            if nums[right] >= nums[mid]:
                right = mid
            # 右边无序时，最小值存在与[mid+1, right] 中
            else:
                left = mid + 1
```
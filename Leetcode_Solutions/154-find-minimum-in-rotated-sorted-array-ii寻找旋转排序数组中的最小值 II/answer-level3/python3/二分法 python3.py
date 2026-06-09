# 题解
旋转排序数组由两个有序子序列构成。
## 二分法
 1. 初始化左指针$l=0$，右指针$r=n-1$
 2. 循环条件$l<r$：
 	* $mid=(l+r)//2$
 	* 若$nums[mid]>nums[r]$。说明$mid$一定在第一个有序数组中。则最小值一定在第二个有序数组中，令$l=mid+1$
 	* 若$nums[mid]<nums[r]$。说明$mid$已经在第二个有序数组中。则最小值为$mid$或$mid$左侧。令$r=mid$
 	* 若$nums[mid]==nums[r]$。此时令$r=r-1$。
 
 3. 返回$nums[l]$
 
 **注意！**算法中两个疑惑点：
 1.为什么要用$nums[mid]$和$nums[r]$比较，而不是和$nums[l]$比较。
 因为是寻找最小值，看如下例子：
 $[1,2,3,4,5]$
 $[2,3,4,5,1]$
 虽然$nums[mid]$都大于$nums[l]$，但是最小值可以在左侧或者右侧。
 2.在$nums[mid]==nums[r]$，为什么令$r=r-1$？
 例子：$[1,1,1,3,1]$
假设$nums[right]$是最小值，有两种情况：
若 $nums[right]$是唯一最小值：则不能满足判断条件 $nums[mid] == nums[right]$，因为 $mid < right$（$left != right$且 $mid = (left + right) // 2$ 向下取整）；
若 $nums[right]$ 不是唯一最小值，由于 $mid < right$ 而 $nums[mid] == nums[right]$，即还有最小值存在于 $[left, right - 1]$ 区间，因此不会丢失最小值。[引自](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/)

### 复杂度分析
 - 时间复杂度：$O(log(n))$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if(not nums):
            return None
        n=len(nums)
        if(n==1):
            return nums[0]
        l=0
        r=n-1
        while(l<r):
            mid=(l+r)//2
            if(nums[mid]>nums[r]):
                l=mid+1
            elif(nums[mid]<nums[r]):
                r=mid
            else:
                r=r-1
        return nums[l]
```
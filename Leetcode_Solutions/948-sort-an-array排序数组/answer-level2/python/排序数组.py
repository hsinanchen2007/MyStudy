# 解题思路 
1 冒泡排序
# 代码
```
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for i in range(n-1):
            for j in range(n-1-i):
                if nums[j]>nums[j+1]:
                    nums[j],nums[j+1]=nums[j+1],nums[j]
        return nums
```
# 选择排序
# 代码
```
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for i in range(n-1):
            min = i
            for j in range(i+1,n):
                if nums[min]>nums[j]:
                    min = j
            nums[i],nums[min]=nums[min],nums[i]
        return nums
```
# 快速排序
# 代码
```
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        def quick_sort(nums,first,last):
            if first>=last:
                return
            mid_value = nums[first]
            low = first
            high = last
            while low<high:
                # high 左移
                while nums[high]>=mid_value and high>low:
                    high -= 1
                nums[low]=nums[high]
                # low 右移
                while nums[low]<mid_value and low < high:
                    low += 1
                nums[high]=nums[low]
            nums[low] = mid_value
            # 递归
            # 对low左边的进行递归
            quick_sort(nums,first,low-1)
            # 对low右边的进行递归
            quick_sort(nums,low+1,last)
        quick_sort(nums,0,n-1)
        return nums
```

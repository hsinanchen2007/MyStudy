### 解题思路
用法：
def find_left_index(self, nums, target):
def find_right_index(self, nums, target):
if left == n or nums[left] != target:
    return [-1,-1]
解法：
二分查找。

![image.png](https://pic.leetcode-cn.com/7dced241fac1d6af5b59307b214e6ecd9fb2875c28083aa0d808c6d6f6844284-image.png)


### 代码

```python
class Solution(object):
    def find_left_index(self, nums, target):
        i = 0
        j = len(nums)
        
        while i < j:
            # print i,j
            mid = (i+j)/2
            # print mid
            if nums[mid] == target:
                # print 'step1'
                j = mid
            if nums[mid] > target:
                # print 'step2'
                j = mid
            elif nums[mid] < target:
                # print 'step3'
                i = mid + 1
 
        return i

    
    def find_right_index(self, nums, target):
        i = 0
        j = len(nums)
        
        while i < j:
            # print i,j
            mid = (i+j)/2
            # print mid 
            if nums[mid] == target:
                i = mid + 1
            if nums[mid] > target:
                j = mid
            elif nums[mid] < target:
                i = mid + 1

        print i
        return i

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """




        n = len(nums)
        if n == 0: return [-1,-1]

        left = self.find_left_index(nums,target)
        right = self.find_right_index(nums,target)-1
        if left == n or nums[left] != target:
            return [-1,-1]
        return [left, right]


```
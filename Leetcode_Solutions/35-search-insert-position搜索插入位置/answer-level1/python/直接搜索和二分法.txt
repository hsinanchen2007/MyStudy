### 方法一
直接搜索查找，28ms

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n=len(nums)
        if n==0:
            return 0

        if target<nums[0]:
            return 0
        if target>nums[n-1]:
            return n

        for i in range(n):
            if target<=nums[i]:
                return i
```

### 方法二
二分法查找

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """       
        n=len(nums)
        if n==0:
            return 0

        if target<nums[0]:
            return 0
        if target>nums[n-1]:
            return n

        left,right=0,n-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]<target:
                left=mid+1
            elif nums[mid-1]<target<nums[mid]:
                return mid
            else:
                right=mid-1
        return left
```
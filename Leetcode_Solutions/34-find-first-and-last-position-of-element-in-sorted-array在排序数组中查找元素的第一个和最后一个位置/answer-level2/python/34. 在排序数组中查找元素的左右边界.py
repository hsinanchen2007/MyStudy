### 解题思路
二分查找变形，套模板
- 分别定义找左边界和找右边界的函数；
- 比常规的二分查找多一次判断，即判断当前mid和其旁边（左或右）是否相等；
- 若不相等，则找到边界；若相等，继续二分；

### 代码

```python3
class Solution:
    def binarySearchLeft(self, nums, target):
        left, right = 0, len(nums)-1
        while left < right:
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            # 比标准的二分多一次判断，分割线上下都是套模板
            ###########################################
            elif nums[mid] > target:
                right = mid - 1
            else:
                # 当mid与mid左边的数相同时，继续二分；不同时说明找到左边界
                if mid>0 and nums[mid-1] == nums[mid]:
                    right = mid-1
                else:
                    return mid
            ###########################################
        # 跳出循环时 left == right, 判断一下是不是要找的数
        if nums[right] == target:
            return right
        else:
            return -1

    def binarySearchRight(self, nums, target):
        left, right = 0, len(nums)-1
        while left < right:
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            ########################################### 
            elif nums[mid] > target:
                right = mid - 1
            else:
                if mid<len(nums)-1 and nums[mid+1] == nums[mid]:
                    left = mid+1
                else:
                    return mid
            ###########################################
        if nums[right] == target:
            return right
        else:
            return -1

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) == 0:
            return [-1, -1]
        left_bound = self.binarySearchLeft(nums, target)
        right_bound = self.binarySearchRight(nums, target)
        return [left_bound, right_bound]

```
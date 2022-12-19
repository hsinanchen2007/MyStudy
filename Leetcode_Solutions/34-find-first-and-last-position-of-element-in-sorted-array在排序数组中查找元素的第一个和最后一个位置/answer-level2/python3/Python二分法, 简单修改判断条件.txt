1. 标准二分法
```
def binary_search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                # 此处需要改造，以便于得到第一个或最后一个target
                return mid
            if target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        return -1
```

2. 改造后的二分法，获取到target后需要判断是否第一个target或最后一个target
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.left_search(nums, target)
        right = self.right_search(nums, target)
        return [left, right]

    
    def left_search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                # 判断是否第一个target，否则继续查找
                if mid > 0 and nums[mid - 1] == target:
                    right = mid - 1
                    continue
                else:
                    return mid
            if target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        return -1
    
    def right_search(self, nums: List[int], target: int) -> int:
        left, right, length = 0, len(nums) - 1, len(nums)
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                # 判断是否最后一个target，否则继续查找
                if mid + 1 < length and nums[mid + 1] == target:
                    left = mid + 1
                    continue
                else:
                    return mid
            if target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        return -1
```



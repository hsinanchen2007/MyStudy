```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return
        n = len(nums)
        start, end = 0, n-1
        leftMin, rightMin = nums[0], nums[0]
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] < nums[end]: # 右边有序
                if nums[mid] < rightMin:
                    rightMin = nums[mid]
                end = mid - 1
            else: #左边有序
                if nums[start] < leftMin:
                    leftMin = nums[start]
                start = mid + 1
        return min(leftMin, rightMin)
```

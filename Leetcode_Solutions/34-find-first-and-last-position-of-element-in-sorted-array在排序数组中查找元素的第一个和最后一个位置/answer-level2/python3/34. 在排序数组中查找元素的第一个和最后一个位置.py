执行耗时:40 ms,击败了99.86% 的Python3用户
内存消耗:13.6 MB,击败了97.49% 的Python3用户
```
    # 通过二分法找到第一个等于 target 的值, 然后以该值向左向右查找边界
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target < nums[mid]:
                right = mid - 1
            elif target > nums[mid]:
                left = mid + 1
            else:
                left = mid
                right = mid
                while left - 1 >= 0 and nums[left - 1] == target:
                    left -= 1
                while right + 1 < len(nums) and nums[right + 1] == target:
                    right += 1
                return [left, right]
        return [-1, -1]
```
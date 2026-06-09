```
 def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 1:
            return [-1, -1]
        # 二分查找
        left = 0
        right = len(nums) - 1
        index = -1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                index = mid
                break
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        # 没找到目标值
        if index == -1:
            return [-1, -1]
        # 找最前和最后目标值，注意边界处理
        i = index
        j = index
        while i >= 0 and nums[i] == nums[index]:
            i -= 1
        while j < len(nums) and nums[j] == nums[index]:
            j += 1

        return [i + 1, j - 1]
```

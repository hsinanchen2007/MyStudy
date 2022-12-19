

    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if target <= nums[0]:
            return 0
        elif target > nums[n-1]:
            return n
        else:
            for i in range(n):
                if nums[i] == target:
                    return i
                elif (nums[i] < target and nums[i+1] > target):
                    return i+1
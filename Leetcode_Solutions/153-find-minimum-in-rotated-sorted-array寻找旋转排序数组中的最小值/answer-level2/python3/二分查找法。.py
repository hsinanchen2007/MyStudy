class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return None
        
        if len(nums) == 1:
            return nums[0]
        
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = (right + left) >> 1  # 右移1为等价于除以2   比较装逼！

            if nums[mid] < nums[mid-1]:  # 如果中间这个数比它左边的还小，直接就找到了。
                return nums[mid]
            elif nums[mid] < nums[right]:  # 如果中间的比右半边数小，说明最小值在左半边，调整右边界
                right = mid - 1
            else:
                left = mid + 1
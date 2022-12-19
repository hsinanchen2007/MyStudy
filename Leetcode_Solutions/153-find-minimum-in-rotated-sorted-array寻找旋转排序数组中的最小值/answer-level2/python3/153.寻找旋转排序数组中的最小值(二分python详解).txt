使用target记录数组最右端的数字，然后用start和end标志寻找区间，如果mid位置上的数字小于等于最右端的数字时，区间向左移动，其余向右移动即可，返回start和end位置上较小值即可。
class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        if nums is None or len(nums) == 0:
            return -1
        
        start, end = 0, len(nums) - 1
        target = nums[-1]
        
        while start + 1 < end:
            mid = start + (end - start) // 2  
            if nums[mid] <= target:         #如果mid位置上的数字小于等于最右端的数字时，区间向左移动
                end = mid
            else:
                start = mid
        return min(nums[start], nums[end])  #最终返回start和end位置上较小的数字即可
            

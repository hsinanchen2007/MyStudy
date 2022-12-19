```
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        size = len(nums)

        if size == 1:
            if nums[0] == target:
                return True
            
            return False
        
        mid = (0 + size-1) // 2

        if nums[mid] != target:
            return False
        # bisect这个包非常好用
        from bisect import bisect_left, bisect_right
        
        # 找到该元素最左边的第一个
        left_index = bisect_left(nums, target)
        # 找到某个元素最右边的第一个
        right_index = bisect_right(nums, target)

        whole_cnt = right_index - left_index

        if whole_cnt > size/2:
            return True
        
        return False
```

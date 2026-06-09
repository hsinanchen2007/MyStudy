**思路:** 遍历数组，在遍历至位置i时，始终维持2元递增序列的最小值cmp，如果当前元素元素nums[i]大于cmp，则返回True。如果遍历完数组没有找到大于cmp的元素，则返回False.

```
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 3:
            return False
        mmin = nums[0]
        cmp = float('inf')
        for i in range(1, len(nums)):
            if nums[i] > cmp:
                return True
            if nums[i] > mmin:
                cmp = min(cmp, nums[i])
            mmin = min(mmin, nums[i])
        return False
```
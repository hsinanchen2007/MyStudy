**该题有重复元素！！！！**；

后来想到，与33产生矛盾的地方就是**可能l与r的位置的元素相同！无法判别目标值应该在哪边，故只需要去掉一边的重复值即可**

**在求mid之前先去一边的重！！！**

中间有重复的元素无所谓，之前想的是分两边的mid，mid_l与mid_r，后来发现这只是减少循环步骤，因为重复的元素会在nums[l]==nums[r]的时候就会去重。      
      
       

```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
    	l, r = 0, len(nums) - 1
    	while l <= r:
    		while l < r and nums[l] == nums[r]:
    			l += 1
    		mid = (l + r) // 2
    		if nums[mid] == target:
    			return True
    		if nums[mid] < target:
    			if nums[l] <= target and nums[l] > nums[mid]:
    				r = mid - 1
    			else:
    				l = mid + 1
    		if nums[mid] > target:
    			if nums[r] >= target and nums[r] < nums[mid]:
    				l = mid + 1
    			else:
    				r = mid - 1
    	return False
```

经提醒，最坏情况的复杂度为o(n)
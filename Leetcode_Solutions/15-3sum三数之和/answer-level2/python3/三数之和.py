```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums_hash = {}  # 用于记录原数组中每个数出现的次数
        result = []
        for num in nums:
            nums_hash[num] = nums_hash.get(num, 0) + 1
        if 0 in nums_hash and nums_hash[0] >= 3:
            result.append([0, 0, 0])
            
        nums = sorted(list(nums_hash.keys()))
        
        for i, num in enumerate(nums):
            for j in nums[i+1:]:
                if num*2 + j == 0 and nums_hash[num] >= 2:
                    result.append([num, num, j])
                if j*2 + num == 0 and nums_hash[j] >= 2:
                    result.append([num, j, j])
                
                dif = 0 - num - j
                if dif > j and dif in nums_hash:
                    result.append([num, j, dif])
        
        return result
```
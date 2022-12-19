Python3 解法
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        target = 0
        res = []
        for i in range(n -2):
            if i > 0 and nums[i] == nums[i-1]: # 选的这个数不能重复
                continue
            if nums[i] + nums[i+1] + nums[i+2] > target: # 最小的结果
                break
            if nums[n-1] + nums[n-2] + nums[i] < target: # 最大的结果
                continue
            l = i + 1
            r = n - 1
            while l < r:
                temp = nums[i] + nums[l] + nums[r]
                if temp == target:
                    res.append([nums[i], nums[l], nums[r]]) 
                    l += 1
                    r -= 1
                    # 去掉重复
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
                elif temp < target:
                    l += 1
                else:
                    r -= 1
                    
        return res            
````
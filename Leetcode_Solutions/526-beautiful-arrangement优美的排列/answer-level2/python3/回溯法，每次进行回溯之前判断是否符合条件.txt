```python3
class Solution:
    def countArrangement(self, N: int) -> int:
        self.count = 0
        nums = [i+1 for i in range(N)]
        self.helper(nums, [])
        return self.count
    
    def helper(self, nums, path):
        if not nums:
            self.count += 1
        for i in range(len(nums)):
            n = len(path)
            if nums[i]%(n+1)!=0 and (n+1)%nums[i]!=0:
                continue
            self.helper(nums[:i]+nums[i+1:], path+[nums[i]])
    
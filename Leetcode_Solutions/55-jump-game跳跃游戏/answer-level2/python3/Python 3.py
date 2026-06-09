```python3 []
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if not nums:
            return False
        c = len(nums)
        pos = [0] * c
        pos[0] = 1
        temp = nums[0]
        pos[1:1+nums[0]] = [1]*nums[0]
        for i in range(1, c-1):
            if pos[i] != 0 and i+1+nums[i]>temp:
                pos[i+1:i+1+nums[i]] = [1]*nums[i]
                temp = i+1+nums[i]
                if temp >= c:
                    break
        if pos[c-1] == 1:
            return True
        else:
            return False
```
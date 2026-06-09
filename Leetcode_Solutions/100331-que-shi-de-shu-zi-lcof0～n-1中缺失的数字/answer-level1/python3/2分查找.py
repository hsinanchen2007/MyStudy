### 解题思路
需要注意递归停止条件

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        s, e = 0, len(nums)-1
        return self.helper(s, e, nums)

    def helper(self, s, e, nums):
        # print(s,e)
        if s==e and nums[s]!=s:
            return s
        elif s==e and nums[s]==s:
            return s+1
        mid = (s+e)//2
        # print(mid)
        if mid == nums[mid]:
            return self.helper(mid+1, e, nums) if mid<e else self.helper(mid, e, nums)
        elif mid < nums[mid]:
            return self.helper(s, mid-1, nums) if s<mid else self.helper(s, mid, nums)


            
```
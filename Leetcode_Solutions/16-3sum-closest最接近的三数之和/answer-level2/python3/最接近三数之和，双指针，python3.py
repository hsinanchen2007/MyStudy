### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = nums[0]+nums[1]+nums[2]
        for i in range(len(nums)-2):
            start = i+1
            end = len(nums)-1
            while start<end:
                if abs(nums[i]+nums[start]+nums[end]-target)<abs(ans-target):
                    ans = nums[i]+nums[start]+nums[end]
                if nums[i]+nums[start]+nums[end]-target>0:
                    end -= 1
                elif nums[i]+nums[start]+nums[end]-target<0:
                    start += 1
                else:
                    return ans
        return ans
```
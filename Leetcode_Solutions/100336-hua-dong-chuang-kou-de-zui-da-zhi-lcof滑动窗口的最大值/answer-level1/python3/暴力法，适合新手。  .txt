### 解题思路
暴力法，永远滴神！
### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        if not nums:
            return ans
        for i in range(0,len(nums)-k+1):
            ans.append(max(nums[i:i+k]))
        return ans
```
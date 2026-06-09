### 解题思路
区间一步一步走。

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        if not nums: return []
        for i in range(len(nums)-k+1):
            a = max(nums[i:i+k])
            ans.append(a)
        return ans
```
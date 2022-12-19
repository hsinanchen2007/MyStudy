### 解题思路
挺简单的一道题

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d = {}
        for i in range(len(nums)):
            if nums[i] in d:
                d[nums[i]] += 1
            else:
                d[nums[i]] = 1
        k = int(len(nums)/3)
        ans = []
        for item in d.keys():
            if d[item] > k:
                ans.append(item)
        return ans
```
### 解题思路
字典解决数组的度

### 代码

```python3
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        left, right, count = {}, {}, {}
        max_ = 1
        for i in range(len(nums)):
            if nums[i] not in left:
                left[nums[i]] = i
                count[nums[i]] = 1
            else:
                right[nums[i]] = i
                count[nums[i]] += 1
                if count[nums[i]] > max_:
                    max_ = count[nums[i]]
        if max_ == 0 or max_ == 1:
            return max_
        minLoc = float('inf')
        for (i, j) in zip(count.keys(), count.values()):
            if j == max_:
                if right[i] - left[i] + 1 < minLoc:
                    minLoc = right[i] - left[i] + 1
        return minLoc

        
```
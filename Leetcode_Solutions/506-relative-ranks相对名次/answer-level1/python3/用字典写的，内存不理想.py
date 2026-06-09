### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRelativeRanks(self, nums):
        player = (sorted(nums, reverse=True))
        guide = {1: 'Gold Medal', 2: 'Silver Medal', 3: 'Bronze Medal'}
        res = {}
        count = 1
        for i in player:
            if count < 4:
                res[i] = guide[count]
            else:
                res[i] = str(count)
            count += 1
        
        rank = []
        for j in nums:
            rank.append(res[j])
        
        return rank
```
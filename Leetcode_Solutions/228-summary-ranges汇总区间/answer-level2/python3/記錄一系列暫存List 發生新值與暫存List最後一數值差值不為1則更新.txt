### 解题思路
記錄一系列暫存List 發生新值與暫存List最後一數值差值不為1則更新

### 代码

```python3
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        
        nums.append(nums[0]-1)
        res, cur = [], [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] - cur[-1] == 1:
                cur.append(nums[i])
            else :
                if len(cur) == 1:
                    res.append(str(cur[0]))
                else:
                    res.append(str(cur[0])+'->'+str(cur[-1]))
                cur = [nums[i]]    
        return res



```
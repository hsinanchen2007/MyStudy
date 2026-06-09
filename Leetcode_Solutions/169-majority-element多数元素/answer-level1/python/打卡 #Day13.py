
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        lens = len(nums)
        tmp = [[],[]]
        for i in range(lens):
            if nums[i] not in tmp[0]:
                tmp[0].append(nums[i])
                tmp[1].append(1)
            else:
                tmp[1][tmp[0].index(nums[i])] += 1
        return tmp[0][tmp[1].index(max(tmp[1]))]
```
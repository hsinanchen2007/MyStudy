### 解题思路
对于nums[i]，将res里已有的所有元素追加nums[i]
然后再将新生成的元素追加到res里
时间复杂度O(n*2)
### 代码

```python3
import copy
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        for i in range(len(nums)):
            tmp = copy.deepcopy(res)
            for j in tmp:
                j.append(nums[i])
                res.append(j.copy())

        return res
```
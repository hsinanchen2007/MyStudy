
#只在46题基础上修改一行代码

```python
from copy import deepcopy

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        result = []
        record = []
        self._permuteUnique(nums, record, result)
        return result

    
    def _permuteUnique(self, nums:list, record:list, result:list) -> None:
        if len(nums) == 0:
            result.append(deepcopy(record))
            return 

        num_set = set(nums)  # 所有相同的元素只遍历一次
        for x in num_set:
            record.append(x)
            nums.remove(x)
            self._permuteUnique(nums, record, result)
            nums.append(x)
            record.pop(-1)
```
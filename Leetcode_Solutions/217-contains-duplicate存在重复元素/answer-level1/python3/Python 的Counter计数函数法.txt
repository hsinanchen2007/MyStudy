
```python []
from collections import Counter
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        obj=Counter(nums)
        for i in obj.keys():
            if obj[i]>1:
                return True
        else:
            return False
```




        
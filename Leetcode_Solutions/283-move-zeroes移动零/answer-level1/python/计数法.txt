

### 代码

```python3
from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        index=0
        for i in range(len(nums)):
            if(nums[i]!=0):
                nums[index]=nums[i]
                index=index+1
        while index<len(nums):
            nums[index]=0
            index=index+1
      
```
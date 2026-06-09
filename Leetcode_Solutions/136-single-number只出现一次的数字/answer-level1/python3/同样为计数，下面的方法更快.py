### 解题思路
同样为计数，下面的方法更快

### 代码

```python3
from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # 遍历取count为1的值 
        # for num in nums:
        #     if nums.count(num) == 1:
        #         return num

        # 听说下面的方法更快
        data = Counter(nums)
        for each in data:
            if data[each] == 1:
                return each
```
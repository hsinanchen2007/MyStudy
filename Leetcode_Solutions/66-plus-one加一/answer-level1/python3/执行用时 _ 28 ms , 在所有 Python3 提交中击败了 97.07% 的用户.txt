### 解题思路
就是int和str之间的转化

### 代码

```python3
from typing import List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] != 9:
            digits[-1] = digits[-1] + 1
            return digits
        else:
            string = ''
            for i in range(len(digits)):
                string = string + str(digits[i])
            number = str(int(string) + 1)
            list1 = list(number)
            return list1
```
### 解题思路
此处撰写解题思路

### 代码

```python3
import math
class Solution:
    def printNumbers(self, n: int) -> List[int]:
      x = int(math.pow(10,n)) -1
      result = []
      for i in range(x):
        result.append(i + 1)
      return result
      

```
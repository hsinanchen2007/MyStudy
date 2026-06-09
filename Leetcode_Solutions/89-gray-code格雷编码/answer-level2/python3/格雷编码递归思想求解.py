### 解题思路
其实在写出了几个格雷码之后，我们是可以发现其中的一些规律性的东西的。
1. n = 0,result0 = [0]
2. n = 1,result1 = [0,1] = [result0,0+2^(1-1)]
3. n = 2,result2 = [0,1,3,2] = [result1,1+2^(2-1),0+2^(2-1)]
从中我们可以发现，存在着递归的思想存在

### 代码

```python3
from typing import List
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            result = [0]
        else:
            result = result1 = self.grayCode(n-1)
            for i in range(2**(n-1)-1, -1, -1):
                result.append(result1[i]+2**(n-1))
        return result

```
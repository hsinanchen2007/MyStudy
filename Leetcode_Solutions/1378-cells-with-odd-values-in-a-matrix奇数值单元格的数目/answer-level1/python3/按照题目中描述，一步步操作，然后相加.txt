### 解题思路
1. 导入numpy建立数组
2. 按照题目中的描述，对行列进行加1操作。
3. 统计奇数的个数：arr%2==1如果为True即=1，False即为0，将array中所有结果相加得到技术的个数

### 代码

```python3
from numpy import *
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        
        arr = zeros((n,m))
        print(arr)
        for x,y in indices:

            arr[x,:] += 1
            arr[:,y] += 1

        return sum(arr%2==1)
```
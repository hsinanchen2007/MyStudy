## 思路
+ 题目是大水题
+ 就是生成一个长度为 n 的数组
+ 然后后半部分从 1 到 n//2 + 1
+ 前半部分从 -1 到 -(n//2 + 1)
+ 这里只是作为使用 numpy 的一个展示
+ 很多时候使用 numpy 来处理矩阵，列表可以显著加速

## 代码
```python
import numpy as np
class Solution:
    def sumZero(self, n: int) -> List[int]:
        a = np.zeros(n,dtype=np.int32)
        a[(n+1)//2:] = np.arange(1,n//2 + 1)
        a[:n//2] = np.arange(1,n//2 + 1) * -1
        return a
```
根据评论区 [@EzioXiang](/u/ezioxiang/) 提到的规则
```
先横竖变换保证第一列全部是1
竖变换保证其他列1比0多
```
使用 numpy 4行代码实现，运行效率是确实低。。

```python
import numpy as np
class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        arr = np.array(A)
        arr[arr[:, 0] == 0] = np.bitwise_xor(arr[arr[:,0] == 0], 1)
        arr[:, np.sum(arr, axis=0) < (arr.shape[0]//2+1)] = np.bitwise_xor(arr[:, np.sum(arr, axis=0) < (arr.shape[0]//2+1)], 1)
        return np.sum(arr * np.logspace(0, arr.shape[1]-1, arr.shape[1], base=2)[::-1].astype(np.int))
```

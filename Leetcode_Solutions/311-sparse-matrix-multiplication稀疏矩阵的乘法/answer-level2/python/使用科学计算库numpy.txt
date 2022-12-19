Python有科学计算库numpy可以使用，直接使用库函数求得矩阵的乘法。

```python
import numpy as np
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        a = np.array(A)
        b = np.array(B)
        return np.matmul(a, b)
```

Leetcode全部题解：[负雪明烛的博客](https://blog.csdn.net/fuxuemingzhu)，已更新800+道题目，欢迎大家关注。
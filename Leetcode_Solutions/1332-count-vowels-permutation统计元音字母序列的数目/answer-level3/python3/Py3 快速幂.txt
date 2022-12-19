Py3 这样就能过，如果n更大的话可以用矩阵快速幂
```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        c = (1, 1, 1, 1, 1)
        for _ in range(n - 1):
            c = (c[1] + c[2] + c[4], c[0] + c[2], c[1] + c[3], c[2], c[2] + c[3])
        return sum(c) % 1000000007
```
快速幂法
~~我觉得应该是快速幂，没看过numpy是怎么实现的，但感觉矩阵幂一定会用快速幂来实现。~~ 看了一下，确实是快速幂

numpy强！需要注意的是，如果是默认类型，那么计算过程中会产生数据溢出（py3的int没有上限，但numpy是用C语言写的，因此有上限），需要强制类型为np.dtype('O')，或者np.object。
```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        import numpy as np
        c = np.mat([(0, 1, 0, 0, 0), (1, 0, 1, 0, 0), (1, 1, 0, 1, 1), (0, 0, 1, 0, 1), (1, 0, 0, 0, 0)], np.dtype('O'))#这里np.object也可以
        return (c ** (n - 1)).sum() % 1000000007
        #return np.linalg.matrix_power(c, n - 1).sum() % 1000000007
        ##以上两种都可以，numpy中matrix的__pow__调用的就是matrix_power
```


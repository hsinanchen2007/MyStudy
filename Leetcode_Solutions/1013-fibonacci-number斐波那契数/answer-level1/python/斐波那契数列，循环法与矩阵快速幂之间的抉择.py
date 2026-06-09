### 解题思路
我们知道，矩阵运算的速度远快于循环，一开始我先用最低级的循环来算，没想到速度和内存消耗都很小
接着我又用矩阵，结合快速幂，结果让人大跌眼镜，无论内存还是时间都远慢于循环
想了一下，是官方测试的数太小了，当N非常大时，其速度远快于循环
循环的时间复杂法为O（n）
快速幂的时间复杂度O（logn）

### 代码

```python3
# 循环
if N == 0:
    return 0
else:
    f1 = 1
    f2 = 1
    list_1 = [f1, f2]
    for i in range(int(N-2):
        list_1[0], list_1[1] = list_1[0] + list_1[1], list_1[0]
    return list_1[0]
# 矩阵＋快速幂
class Solution:
    def fib(self, N: int) -> int:
        import numpy as np
        f0 = 0
        f1 = 1
        if N == 0:
            return 0
        elif N == 1:
            return 1
        else:
            _matrix = np.array([[1, 1], [1, 0]])
            f_matrix = np.array([[f1], [f0]])
            number = N - 1
            while not number == 1:
                if number % 2 == 0:
                    _matrix = np.dot(_matrix, _matrix)
                    number = number / 2

                elif number % 2 != 0:
                    number = number - 1
                    f_matrix = np.dot(_matrix, f_matrix)
                    _matrix = np.dot(_matrix, _matrix)
                    number = number / 2
            f_matrix = np.dot(_matrix, f_matrix)
            return f_matrix[0][0] 
```
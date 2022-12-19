其实看到这题第一反应是这是一个2D卷积操作，而且卷积核是固定的，所以实现思路就有两种：

# 调库
```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        import numpy as np
        from scipy import signal
        np_mat = np.array(mat)
        np_filter = np.ones((2 * K + 1, 2 * K + 1))
        res = signal.convolve2d(np_mat, np_filter, mode='same')
        return res.astype(int).tolist()
```

# 普通解法
先对行进行卷积得到`ans`1，在对`ans1`列进行卷积得到最终结果。
```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        import numpy as np
        m = len(mat)
        n = len(mat[0])
        ans = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if j - K < 0:
                    tmp = 0
                else:
                    tmp = j- K
                ans[i][j] = sum(mat[i][tmp:j+K+1])
        # print(ans)
        ans2 = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i - K < 0:
                    tmp = 0
                else: 
                    tmp = i - K
                if i + K + 1 >= m:
                    tmp2 = m
                else:
                    tmp2 = i + K + 1
                ans2[i][j] = sum([ans[_][j] for _ in range(tmp, tmp2)])
        # print(ans2)
        return ans2
```
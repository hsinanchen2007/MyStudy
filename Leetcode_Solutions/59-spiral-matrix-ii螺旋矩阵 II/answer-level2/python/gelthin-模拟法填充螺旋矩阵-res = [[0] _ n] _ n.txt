### 解题思路
类似习题 [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

#### 自己的解法是 螺旋矩阵，模拟法，每一步模拟螺旋的走法。

#### 看了一个更优秀的解答 [设定边界](https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/)
避免了使用一个 marked 数组，也避免了撞墙后修改方向，速度也快了一些。
首先设置四个边界， left, right, top, bottom = 0, n-1, 0, n-1

控制走的时候不要越过边界，当走完一段时，就更新上面的边界值。

自己写的代码，报了几次 BUG， 对于特例 n=1, n=2, n=3 要想清楚，还是有一点复杂。

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return []
        
        # 设定边界法
        matrix = [[None]*n for i in range(n)]        
        
        left, right, top, bottom = 0, n-1, 0, n-1
        val = 1
        while val <= n*n:
            i = top 
            # for j in range(right+1): BUG, 漏了 left
            for j in range(left, right+1):  # 最上方从左到右的一段 [1,3]
                matrix[i][j] = val
                val += 1
            top += 1  # 至此，最上面一行被删去, 只需考虑 [[8,9,4],[7,6,5]]

            # 即使当 n 为奇数，本该在这里停止，
            # 特例对于 n=1, 由于下面 top > bottom, 不会运行，但 right -= 1 会运行，导致 left 到 right 也不会运行

            j = right
            for i in range(top, bottom+1):# 最右边 从上到下的一段 [4;5]
                matrix[i][j] = val
                val += 1
            right -= 1 # 至此，最右边一行被删去, 只需考虑 [[8,9],[7,6]]

            i = bottom
            for j in range(right, left-1, -1):
                matrix[i][j] = val
                val += 1
            bottom -= 1 # 至此，最下边一行被删去, 只需考虑 [[8,9]]

            j = left
            for i in range(bottom, top-1, -1):  # top-1 而不是 top+1
                matrix[i][j] = val
                val += 1
            left += 1 #至此，最左边一行被删去, 只需考虑 [[9]]
        return matrix
```


#### 讨论 [我二维数组初始化用来 res = [[0] * n] * n 为什么就不行呢?](https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/309054)
注意到 `[x]*n` 默认是做浅拷贝，
+ 浅拷贝也是 copy, 只是只 copy 一层而已，所以 `[0]*n` 确实是 `n` 个 `0` 的副本 `[0,0,0,...,0]`, 更新互补干扰。
+ 但是浅拷贝不会去递归复制，对于 `[[0,0]]*n`, 记 `[0,0]` 的地址为 `id`, 其实是 `[id]*n`, 得到了 `[id, id, id, ...]` 这些 `id` 指向了同一个对象 `[0,0]`, 因此会在这一个对象上面反复修改，导致出错。



### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return []
        
        # matrix = [[i*n+(j+1) for j in range(n)] for i in range(n)]
        
        # # 旋转矩阵
        # for i in range(n):
        #     for j in range(i+1, n):
        #         matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j] 
        # # 对每一行，左右颠倒
        # for i in range(n):
        #     matrix[i][:] = matrix[i][::-1]  # 这里不可以用 matrix[i] = matrix[::-1]
        # return matrix
        # 犯蠢了, 错把旋转矩阵的套路往上套了，根本不对

        # 模拟法
        matrix = [[None for j in range(n)] for i in range(n)]
        marked = [[False for j in range(n)] for i in range(n)]
        
        x, y = 0, 0
        dx, dy = [0,1,0,-1], [1,0,-1,0]
        k = 0

        for val in range(1, n*n+1):
            matrix[x][y] = val
            marked[x][y] = True
            nx, ny = x+dx[k], y+dy[k] 
            if not (0<=nx<n) or not (0<=ny<n) or marked[nx][ny]:
                k = (k+1)%4
                nx, ny = x+dx[k], y+dy[k] 
            x, y = nx, ny
        return matrix
```
### 解题思路
1.  空间复杂度： O(nsize + msize) ； 时间复杂度：O(nsize + msize) * 2
    - 思路简洁

2. [将行列信息存放在原数组的第一行和第一列](https://leetcode-cn.com/problems/zero-matrix-lcci/solution/jiang-xing-lie-xin-xi-cun-fang-zai-yuan-shu-zu-de-/)
    - 思路有点绕，但确实是最优的方法
    - matrix[0][0] 需要特殊处理
    - matrix[i][0]  记录i行需要清零
    - matrix[0][j] 继续j列需要清零
 
### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        nsize = len(matrix)
        if nsize < 1:
            return matrix 
        
        msize = len(matrix[0])
        nset = set()
        mset = set()
        
        for i in range(nsize):
            for j in range(msize):
                if matrix[i][j] == 0:
                    nset.add(i)
                    mset.add(j)
        

        for h in nset:
            for j in range(msize):
                matrix[h][j] = 0
        
        for s in mset:
            for i in range(nsize):
                matrix[i][s] = 0
        
        return matrix
```
#### 方法2
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        nsize = len(matrix)
        if nsize < 1:
            return matrix 
        
        msize = len(matrix[0])
        hen, shu = False, False 
        for i in range(nsize):
            for j in range(msize):
                if matrix[i][j] == 0:
                    if i == 0:
                        hen = True
                    if j == 0:
                        shu = True 
                    
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        

        for i in range(1, nsize):
            if matrix[i][0] == 0:
                for j in range(1, msize):
                    matrix[i][j] = 0
        
        for j in range(1, msize):
            if matrix[0][j] == 0:
                for i in range(1, nsize):
                    matrix[i][j] = 0
        
        if hen:
           for j in range(1, msize):
                matrix[0][j] = 0

        if shu:
           for i in range(1, nsize):
                matrix[i][0] = 0 
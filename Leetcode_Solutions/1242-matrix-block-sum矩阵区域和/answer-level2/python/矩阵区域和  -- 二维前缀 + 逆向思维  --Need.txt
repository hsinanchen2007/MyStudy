### 解题思路
1. [元素和小于等于阈值的正方形的最大边长](https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solution/yuan-su-he-xiao-yu-deng-yu-yu-zhi-de-zheng-fang-2/)
    - 暴力求解写无bug代码，也不容易
    - 二维前缀

2. **逆向思维，通过间接求救，几何图形的组合求解，使得复杂问题变得简答**

### 代码

```python3
''''
class Solution:
    
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        if K < 0:
            return None 
        nsize = len(mat)
        if nsize < 1:
            return None
        
        msize = len(mat[0])
        r, c = 0, 0
        res = [[0] * msize for i in range(nsize)]
        while r < nsize:
            c = 0  ## error 2 ： 无 c=0
            while c < msize:
                r1, c1 = max(0, r-K), max(0, c-K)
                r2, c2 = min(r+K, nsize-1), min(c+K, msize-1) ##  nsize msize 弄反了
                
                res[r][c] = self.sum_mat(mat, r1, r2, c1, c2)
                c += 1
            r += 1
        return res ## error 1 无返回

    def sum_mat(self, mat, r1, r2, c1, c2):
        re = 0
        for i in range(r1, r2+1):
            for j in range(c1, c2+1):
                re += mat[i][j]
        
        return re
    
    # Wrong 4: TimeOut....



'''

class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        if K < 0:
            return None 
        nsize = len(mat)
        if nsize < 1:
            return None
        
        msize = len(mat[0])
        
        dp = [[0] * (msize+1) for _ in range(nsize+1)]

        for i in range(1, nsize+1):
            for j in range(1, msize+1):       
                #dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]  + mat[i][j]
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1]        
        res = [[0] * msize for i in range(nsize)]
        r, c = 0, 0
        while r < nsize:
            c = 0  ## error 2 ： 无 c=0
            while c < msize:
                r1, c1 = max(0, r-K), max(0, c-K)
                r2, c2 = min(r+K, nsize-1), min(c+K, msize-1) ##  nsize msize 弄反了
                #  ans[i][j] = dp[x2+1][y2+1] - dp[x1][y2+1] - dp[x2+1][y1] + dp[x1][y1];
                res[r][c] = dp[r2+1][c2+1] - dp[r1][c2+1] - dp[r2+1][c1] + dp[r1][c1]
                c += 1
            r += 1
        return res ## error 1 无返回

    
    # Wrong 4: TimeOut....
```
### 解题思路
本题basecase不好写，因为没法确定dp表应该从哪个位置开始填
所以就不使用动态规划了，直接暴力递归会超时
所以加一个dp表，记忆化搜索

### 代码

```python3
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if matrix is None or matrix == []:
            return 0
        dp = [[0 for i in range(len(matrix[0]))] for i in range(len(matrix))]
        res = 1
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = max(res,self.process(matrix,i,j,dp))
        return res
    
    def process(self,matrix,i,j,dp):
        '''
        以i，j开头的最长递增路径
        '''
        if dp[i][j] != 0:
            return dp[i][j]
        res = 1
        p1,p2,p3,p4 = 1,1,1,1
        if i-1 >=0 and matrix[i][j] < matrix[i-1][j]:
            p1 += self.process(matrix,i-1,j,dp)
        if j-1>=0 and matrix[i][j] <matrix[i][j-1]:
            p2 += self.process(matrix,i,j-1,dp)
        if i+1<len(matrix) and matrix[i][j]<matrix[i+1][j]:
            p3 += self.process(matrix,i+1,j,dp)
        if j+1 < len(matrix[0]) and matrix[i][j]<matrix[i][j+1]:
            p4 += self.process(matrix,i,j+1,dp)
        dp[i][j] =  max(res,p1,p2,p3,p4)
        return dp[i][j]
```
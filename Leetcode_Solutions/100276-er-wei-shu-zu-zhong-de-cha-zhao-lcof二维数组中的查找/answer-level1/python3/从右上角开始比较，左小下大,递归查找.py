### 解题思路
从右上角开始比较，左小下大,递归查找

### 代码

```python
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        def dis(m,n,target,matrix,maxm):
            if m > maxm or n < 0:
                return False

            if matrix[m][n] == target:
                return True
            else:
                if target > matrix[m][n]:
                    m += 1
                else: n -= 1

                return dis(m,n,target,matrix,maxm)

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        maxm,maxn = len(matrix), len(matrix[0])
        return dis(0,maxn -1,target,matrix,maxm-1)

    


```
### 解题思路
这个矩阵可以看成一个子女有部分重叠的搜索二叉树（右上角为根）

### 代码

```python3
#这个矩阵可以看成一个子女有部分重叠的搜索二叉树（右上角为根）
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        n = len(matrix)
        m = len(matrix[0])
        i=0
        while(m>0 and i<n):
            tmp = matrix[i][m-1]
            #print(tmp)
            if tmp==target:
                return True
            elif tmp>target:
                m=m-1
            else:
                i=i+1
        return False

```
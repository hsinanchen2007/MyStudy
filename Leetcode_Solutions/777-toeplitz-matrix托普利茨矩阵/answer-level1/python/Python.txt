### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        row=len(matrix)
        if row==0:
            return False
        col=len(matrix[0])
        dict={}
        for i in range(row):
            for j in range(col):
                if i-j not in dict:
                    dict[i-j]=matrix[i][j]
                elif dict[i-j]!=matrix[i][j]:
                    return False
        return True
```
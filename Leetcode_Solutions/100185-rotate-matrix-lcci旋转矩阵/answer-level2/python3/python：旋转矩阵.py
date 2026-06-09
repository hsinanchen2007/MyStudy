### 解题思路
旋转就是对称，不使用足够的额外空间就是经过数次翻转，就可以完成旋转的等价效果
强调：在python里，其实迭代+替换=足额的额外空间，他的交换就是一种拷贝，一旦遍历，相当于每个拷贝一份，实际空间一点没少！

### 代码

```python3
#额外空间
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length=len(matrix)
        ans=[]
        for i in range(length):
            row=[]
            for j in range(length):
                row.append(matrix[length-j-1][i])
            ans.append(row)
        matrix[:]=ans
#不使用额外空间
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        length = len(matrix)
        for i in range(length // 2):
            for j in range(length):
                matrix[i][j], matrix[length-i-1][j] = matrix[length-i-1][j], matrix[i][j]
        for i in range(length):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```
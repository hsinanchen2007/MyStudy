### 解题思路
![ff55a6b3e93ef5e70c661c59628698a.png](https://pic.leetcode-cn.com/f0dccd6ae9208a055e84d56a2b67654bce7f8bf06fb7958902a06e0d9b9c5420-ff55a6b3e93ef5e70c661c59628698a.png)

关键点：两次遍历；第一次转置（中心对称），第二次 依次交换第一列和最后一列、第二列和倒数第二列...(列对称)

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        def swap(i1,j1,i2,j2):
            matrix[i1][j1],matrix[i2][j2] = matrix[i2][j2],matrix[i1][j1]
            
        for i in range(n):
            for j in range(i+1,n):
                swap(i,j,j,i)

        for i in range(n):
            for j in range(n//2):
                swap(i,j,i,n-1-j)        
```
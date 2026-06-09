### 解题思路
![image.png](https://pic.leetcode-cn.com/d39050c525e078078a54b76280b4bf7462994dbaeaa616e025498b797202e74c-image.png)

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length = len(matrix)
        matrix[:] = matrix[::-1]   # 把行数进行对掉，由0、1、2、3变为3、2、1、0
        
        for i in range(length):    
            for j in range(i):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]

```
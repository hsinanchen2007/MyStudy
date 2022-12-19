### 解题思路
对于一个正方形，旋转90度可以理解为如下图所示的两步对称。
![说明图.png](https://pic.leetcode-cn.com/efa4f44f48fb3c6239eb3b541eddd231f3e5b2f6dc3bbd8854db3f8bfe9af689-%E8%AF%B4%E6%98%8E%E5%9B%BE.png)
其中，对角线对称相当于matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
中点连线对称相当于逆序即matrix[i].reverse()

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) > 1:
            for i in range(len(matrix)-1):
                for j in range(i+1,len(matrix)):
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
            for i in range(len(matrix)):
                matrix[i].reverse()


```
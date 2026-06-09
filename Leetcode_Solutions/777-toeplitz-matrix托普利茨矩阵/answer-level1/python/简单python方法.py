### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/7e13ae6fd72db6307691be3ebeed8a40678165f1ca4bda0dbad9a50458e8ed26-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python3
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        n=len(matrix)
        n1=len(matrix[0])
        for i in range(n-1):
            for j in range(n1-1):
                if matrix[i][j]!=matrix[i+1][j+1]:
                    return 0
        return 1



        

```
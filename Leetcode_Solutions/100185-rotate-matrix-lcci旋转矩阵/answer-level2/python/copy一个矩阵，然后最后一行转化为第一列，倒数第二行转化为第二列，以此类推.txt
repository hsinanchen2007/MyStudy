### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/b511a4f5e87e3ec83fa96a5428b8e951321e0f45cd7e0bd02432de26a96e89ce-image.png)


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix_copy=[[i for i in j ]  for j in matrix]
        n=len(matrix)
        index=0
        index1=n-1
        while index<n:
            temp=matrix_copy[index1]
            for i,j in enumerate(temp):
                matrix[i][index]=j
            index1=index1-1
            index=index+1

            


```
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix[:]=([[matrix[-i-1][j] for i in range(len(matrix))]for j in range(len(matrix))])
```
![image.png](https://pic.leetcode-cn.com/32f170c9341d13e6cac9c692fd5a1f2cbb022e27c705ecd1a03290e14911aa57-image.png)


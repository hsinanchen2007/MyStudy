### 解题思路
同习题 [面试题 01.07. 旋转矩阵](https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/gelthin-duo-chong-jie-fa-by-gelthin/)

参见题解 [一次性交换](https://leetcode-cn.com/problems/rotate-image/solution/yi-ci-xing-jiao-huan-by-powcai/)


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 一步到位需要找规律
        n = len(matrix)
        for i in range(n//2): # 每次都是一圈，一共只有 n//2 圈需要处理
            for j in range(i, n-1-i): # 对于第 i 圈(i=0,1,...)，j 的取值范围是 [i, n-1-i-1]
                matrix[i][j], matrix[j][n-i-1], matrix[n-1-i][n-1-j], matrix[n-1-j][i] = \
                matrix[n-1-j][i], matrix[i][j], matrix[j][n-i-1], matrix[n-1-i][n-1-j]
    



```
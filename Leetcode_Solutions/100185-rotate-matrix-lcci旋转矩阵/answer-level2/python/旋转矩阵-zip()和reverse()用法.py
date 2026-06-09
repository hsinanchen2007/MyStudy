### 解题思路
**（1）代码输出结果**
![image.png](https://pic.leetcode-cn.com/5173c379e78725d30280138708bbe006807ae3f0a2c274225962a12ee2c103b7-image.png)

**（2）文字思路**
借助 zip() 方法对矩阵进行对角线翻转
再借助 reverse() 方法对列表进行逆转
**（3）关键tips**
zip() 作用于矩阵，输出表项类型为元组的列表，用法参考：
https://blog.csdn.net/zhu_liangwei/article/details/7967237?
例如，
>>> matrix = [[1,2,3],[4,5,6],[7,8,9]]
>>> list(zip(*matrix))
>>> [(1, 4, 7), (2, 5, 8), (3, 6, 9)]

重要的一点是，此题要求 not return， 所以需要保证去除中间变量，最后作用于matrix本身

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        mmatrix = list(zip(*matrix))
        for i in range(len(matrix)):
            matrix[i] = list(mmatrix[i])
            matrix[i].reverse()



```
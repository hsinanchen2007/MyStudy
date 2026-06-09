### 解题思路
1.转置矩阵，翻转每一行
python列表翻转的方法：
（1）arr = arr[::-1]
（2）arr = list(reversed(arr))
2.转置矩阵，翻转每一行
向量化编程
zip() 函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的对象。
```
a = [1,2,3]
b = [4,5,6]
c = [4,5,6,7,8]
zipped = zip(a,b) # 打包为元组的列表[(1, 4), (2, 5), (3, 6)]
zip(a,c)  # 元素个数与最短的列表一致[(1, 4), (2, 5), (3, 6)]
zip(*zipped)   *zipped解压，返回二维矩阵式[(1, 2, 3), (4, 5, 6)]
```
3.旋转一次
图像旋转，实际是这四个位置上的数对应旋转
![1.png](https://pic.leetcode-cn.com/6cc8b5536b0837d1c49cd3b91b9fc0a7d7fc2c7a23c0f1c681f5b22aa614b309-1.png)
因此，需要找到这四个位置索引的相互关系：
matrix[i][j]--> matrix[j][n-i-1] --> matrix[n-i-1][n-j-1] --> matrix[n-j-1][i]
注意两个边界条件
行只需遍历一半 ，[0,n//2)[0,n//2)
列需要在[i,n-i-1)[i,n−i−1)内

### 代码

```python3
class Solution:
    
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for x in range(1,len(matrix)):
            for y in range(x):
             matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
        for index,arr in enumerate(matrix):
            matrix[index] =  list(reversed(matrix[index]))
            #matrix[index] = matrix[index][::-1]
        return matrix   
    
    '''
    def rotate(self, matrix: List[List[int]]) -> None:
        #matrix[:] = list(map(lambda x:list(x)[::-1], zip(*matrix)))
        matrix[:] = list(map(lambda x:list(x), zip(*reversed(matrix))))    
        return matrix
    '''

    '''
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix) 
        for i in range(n//2):
            for j in range(i, n - i - 1):
                matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1],matrix[n-j-1][i] = \
                matrix[n-j-1][i], matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1]
    '''



```
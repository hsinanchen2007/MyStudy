先来个简单的，可以使用额外空间
那么我们就直接复制一份数组然后来操作就可以了
每个元素的坐标相当于是一个向量，我们给他乘上一个旋转矩阵

![image.png](https://pic.leetcode-cn.com/3d0e707d0a6c30b8154dbad96ae47e3b4ce0e8024f20cdced24e51415f37f5c7-image.png)
就可以得出来旋转90°后的向量了，也就是旋转90°后的新坐标
矩阵是[[0,1],[-1,0]]，就是x2 = y1  y2 = -x1
也就是说比如原来是0,0，结果就是0，0，而如果是1,1，结果就是1，-1
那么问题来了，现在的坐标从原来的0，0 ——> N-1,N-1变到了0，0第一象限——>N-1，1-N，第四象限
所以还得给他平移回来，给Y+N-1就可以了
然后试了一下发现我转反了，好尴尬，不过改回来就好了
```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        tempMatrix = [[matrix[row][col] for col in range(len(matrix[0]))] for row in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = tempMatrix[-j+N-1][i]

```
跑一下，果然快的狠，就是内存占用有点高，（不过咱们还是打败了60%）

![image.png](https://pic.leetcode-cn.com/564aae264386d64c09c01aa692d8538940a21db9cd117bca82a491c2ee2faa01-image.png)
接下来考虑一下题目里说的不占用额外空间
那就要考虑每次修改一个数后会影响后面的哪些操作
![image.png](https://pic.leetcode-cn.com/fde0b5adf07a384ae8cc8a1d93cee2b5b58cc36816570870738407387e9035f4-image.png)

很容易想到应该是有顺时针四个四个的数做循环的，我们如果能同时操作这四个数就可以了
还是用刚才的解法，多加一点，让他一步操作四个数
遍历也不需要遍历全部点了，第一行遍历第一个数到倒数第二个数（倒数第一个数被第一个数操作过了），第二行遍历第二个数到倒数第三个数，以此类推
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        for i in range(len(matrix)//2):
            for j in range(i,len(matrix[0])-i-1):#减一是为了不让角上转2次
                matrix[i][j], matrix[-j+N-1][i] , matrix[-i+N-1][-j+N-1] , matrix[j][-i+N-1] = \
                matrix[-j+N-1][i] , matrix[-i+N-1][-j+N-1] , matrix[j][-i+N-1],matrix[i][j]
```
这次内存占用打败了100不过用时太差了吧。
![image.png](https://pic.leetcode-cn.com/84bb8dba79126135cffe416e035fa101894596594b11b5037ef1c1b6761fd8ce-image.png)

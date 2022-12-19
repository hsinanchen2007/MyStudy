### 解题思路
这一题其实是数学问题（线性代数：矩阵变换）的实际应用，根据旋转90度的特点，可以看出只要把矩阵的每个元素按照副对角线先和对应的元素替换
即：a[i][j]  <-->  a[j][i]
然后再逆置每一行a[i][::-1],就可以得到结果了。
#### 解决：
问题就转化为了替换对角线元素的方法了，逆置就比较简单，通过分析，可以看到只需要逆置矩阵的上三角或者下三角的元素就可以了，转化为数字下标就是：
i=0,j=0
i=1,j=0,1
i=2,j=0,1,2
i=3,j=0,1,2,3
...
i=N-1,j=0,1,2,...,N-1

可以看到j的取值是根据i来改变的，这就比较简单的写出了算法的核心嵌套部分
```python3
for i in range(N):
    for j in range(j):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```
> python中交换变量值的方法：a，b=b，a，而在C/C++中要想使用原地交换，可以用到异或操作（^）

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        # 沿着主对角线交换
        for i in range(N):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range(N):
            matrix[i] = matrix[i][::-1]
```
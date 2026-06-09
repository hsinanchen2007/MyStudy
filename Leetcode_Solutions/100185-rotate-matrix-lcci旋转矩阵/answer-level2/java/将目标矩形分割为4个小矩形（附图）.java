由题目可知，矩阵大小为 n x n，所以分两种情况来讨论，
##### 1. n为偶数
当n为偶数时，较为简单，可以将目标矩阵分割为四个较小的矩阵，然后遍历各个小矩阵，依次进行交换操作。
```
    int temp = matrix[i][j];
    matrix[i][j] = matrix[n - j - 1][i];
    matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
    matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
    matrix[j][n - i - 1] = temp;
```
![image.png](https://pic.leetcode-cn.com/c880c6002849578332a842e119dc4f1b42e5337d667880ed030e2eefafa78afc-image.png)

##### 2. n为奇数
其中奇数又要分两种情况来讨论
* n=1
当n=1时，矩阵不需要旋转，直接跳过即可
* n>1
当n为大于1的奇数时（如图所示），可以将矩阵分割为四块相同大小的矩形（绿色部分），边长分别为`n/2`和`n/2+1`，之后的操作同上。

![image.png](https://pic.leetcode-cn.com/f46e4496a4a4e340cf252e86bd5cbad1cfe17821434170ebcbd0581520423d3f-image.png)

##### 3. 最后附上完整代码
![image.png](https://pic.leetcode-cn.com/f3d35cc3c99a9990d0cc5034e83fffcb12667665e28e1d66fd7af05d248e461c-image.png)







这题我首先想到的是递归的思路，我们先来看看n=3和n=4的两种情况。对于n=3的情况，其实就是外围这一圈数字[1,2,3,6,9,8,7,4]围绕着中间的5进行旋转，旋转的主要操作就是外围的数据进行移位，然后对于n=4的情况，就是将外围的数字旋转两遍，如下图所示，第一轮是最外围红色数字，第二轮是内圈蓝色的数字。

![Rotate Image.png](https://pic.leetcode-cn.com/c62d3343a1a2cc96431269588506b8adcd8e4f8b1944d86f8054adb510d66d7f-Rotate%20Image.png)

既然是递归，那么就要考虑递归的参数。

首先，需要被原地旋转的矩阵本身肯定是需要被传递进去的，而且也是要以指针的方式传参。

另外就是每一轮旋转时需要移动的位数，比如在`n=4`的情况下，第一轮，需要移动`n-1=3`位，第二轮的时候已经将旋转好的外围数据去除，此时只需要移动1位，也就是说，每次递归调用，元素移动的位数是以2递减的，那么需要一个变量来表示这个值。

然后，每轮旋转开始时的元素在原数组当中的下标是每轮递增的，比如在n=4时，第一轮的开始元素`A11（5）`在原二维数组当中的下标是`A[0][0]`，第二轮的开始元素`A22（4）`在原二维数组当中的下标则是`A[1][1]`，这个下标`firstIndex`变量也是要在递归函数当中修改。

下面来看看每一轮递归调用旋转的具体实现过程：可以参考上图n=4的情况。

首先这个旋转需要循环`n-1`次，然后每次就是将每一行除最后一个元素外的其它元素换到另外一列上面，因为一共四条边，每次循环一共需要进行4次。

具体代码如下：


```c []
void rotateSolver(int** matrix, int firstIndex, int n)
{
    if (n <= 1)
    {
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = matrix[firstIndex][firstIndex + i];
        matrix[firstIndex][firstIndex + i] = matrix[firstIndex + n - 1 - i][firstIndex];
        matrix[firstIndex + n - 1 - i][firstIndex] = matrix[firstIndex + n - 1][firstIndex + n - 1 - i];
        matrix[firstIndex + n - 1][firstIndex + n - 1 - i] = matrix[firstIndex + i][firstIndex + n - 1];
        matrix[firstIndex + i][firstIndex + n - 1] = tmp;
    }
    rotateSolver(matrix, firstIndex + 1, n - 2);
}



void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    rotateSolver(matrix, 0, matrixSize);
}
```



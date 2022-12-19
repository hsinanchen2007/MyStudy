### 解题思路
这题坑在returnColumnSize是啥意思，直观来看就是指我们返回的二维数组的每行列坐标大小。

也就是指每行杨辉三角的数字个数。所以系统需要得到的是一个数组，那为什么不直接传int*类型的参数进来，而是要传一个二级指针呢？
实际上，由于C语言传值调用（传指针也只是传指针存的地址值，generate函数接收到的只是复制的一个指针，也就是一个地址值）的特性，int*参数实际上不能用于修改主调函数的指针，而只能用于修改其所指的内存中的内容。

在本题中，这个指针并未初始化空间，需要在generate函数内malloc分配。这就带来一个问题，malloc函数分配实际上是分配一块空间，并让指针指向这块空间，也就是需要修改指针本身，而不是修改指针所指内存中的内容，因此，需要一个二级指针，用来控制那个一级指针，让他指向malloc得到的那块空间。

实际上这是由于C缺乏引用带来的麻烦，C++就不会这样了。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSize)
{
    *returnSize = numRows;
    int** res = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSize = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSize)[i] = i + 1;
        res[i] = (int*)malloc(sizeof(int) * (i + 1));
        res[i][0] = 1;
        res[i][i] = 1;
    }
    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}
```
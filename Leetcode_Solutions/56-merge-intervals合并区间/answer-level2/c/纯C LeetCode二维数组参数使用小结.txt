### 解题思路
纯C 先对开始和结尾值排序 再依次连接 主要是总结了二维数组使用框架

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 要被C语言的函数参数搞疯了，这里总结一下用法，之后就按这个框架使用，专心于算法，不要再在语法调试上浪费时间了
// 定义输入输出参数
#define IN 
#define OUT
// 定义框架
#define __________FRAME_START__________
#define __________FRAME_END__________

static int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
// 输入参数：intervals是数组指针，常规用法
// 输入参数：intervalsSize是数组行数，常规用法
// 输入参数：intervalsColSize是数组列数指针，我又不去改它列数，为什么要指针而不是整型，求指教，划为迷惑用法
// 输出参数：returnSize是返回数组行数，此处指定方便平台编译，可以理解，因此默认需要手动初始化，也就是印证了上面Note的说法，常规用法
// 输出参数：returnColumnSizes是返回列数的数组指针，非常迷惑，极尽困扰，稍一不慎，显得自己很笨，先说明它不是返回二维数组的二级指针，用法如下分解，归为变态用法
int** merge(IN int** intervals, IN int intervalsSize, IN int* intervalsColSize, OUT int* returnSize, OUT int** returnColumnSizes){
    int* pStart = (int*)malloc(intervalsSize * sizeof(int)); 
    int* pEnd = (int*)malloc(intervalsSize * sizeof(int));

    __________FRAME_START__________

    int row = 0; // 定义行列，二维数组肯定会用到
    int col = 0;
    *returnSize = 0; // 初始化returnSize

    int** pRes = (int**)malloc(intervalsSize * sizeof(int*));
    // 在堆空间分配二维数组，所以用malloc方法，不能在栈空间直接定义数组，不然无法返回
    // 定义返回数组的二级指针，元素个数为行数，我一般把二维数组看成一个顺序表，每个结点是一个数组
    // 若用returnColumnSizes = (int**)malloc(intervalsSize * sizeof(int*));方法定义，不创建新指针变量虽不报错但输出结果会有问题
    for (row = 0; row <= intervalsSize - 1; row++)
    {
        pRes[row] = (int*)malloc(*intervalsColSize * sizeof(int)); // 为每个结点分配一个数组空间，元素个数为列数
        pStart[row] = intervals[row][0];
        pEnd[row] = intervals[row][1];
    } // 此时返回的二维数组创建完毕
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int)); 
    // 为神秘的returnColumnSizes指针变量初始化分配一段空间
    // 元素个数为行数，每个元素用来存放该行的列数

    __________FRAME_END__________

    qsort(pStart, intervalsSize, sizeof(int), comp);
    qsort(pEnd, intervalsSize, sizeof(int), comp);

    for (row = 0; row <= intervalsSize - 1; row++)
    {
        __________FRAME_START__________

        pRes[*returnSize][0] = pStart[row]; 
        // 为返回数组赋值，此处用到了returnSize指针变量，其内容是行数下标，因此注意要加*
        // 当然也可以定义新的下标变量count，最后赋值给returnSize就行，平台会拿*returnSize去卡返回的二维数组的有效空间
        for ( ; row <= intervalsSize - 2; row++)
        {
            if (pStart[row + 1] > pEnd[row])
            {
                break;
            }
        }
        pRes[*returnSize][1] = pEnd[row];
        (*returnColumnSizes)[*returnSize] = 2;
        // 坑货来了，这里要每次给returnColumnSize赋值列数值，若列数不同还有点用，若列数相同顿显诡谲
        // 注意优先级，[]的优先级比*高，所以要加括号，因为是给*returnColumnSizes分配了空间，没对returnColumnSizes分配过空间
        (*returnSize)++;
        // 这里自增就行，最后反正长度和下标相差1，这里把returnSize当作下标用刚好抵消了

        __________FRAME_END__________
    }

    return pRes;
}
```
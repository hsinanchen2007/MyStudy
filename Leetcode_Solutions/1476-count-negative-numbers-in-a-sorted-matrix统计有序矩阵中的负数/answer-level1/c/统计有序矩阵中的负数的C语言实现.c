### 解题思路
该题解法简单，主要是考察**迭代**思想，解决思路如下：
* 入参检查，如果grid == NULL，返回0
* 使用嵌套循环的方法，依次遍历并判断矩阵中的各元素
* 循环结束后，返回矩阵中小于0的元素个数

本题的时间复杂度为O(n^2),空间复杂度为O(1)。

**Note：函数形参中gridColSize传入的是int型指针，记得解指针并获取列数。**

### 代码

```c
int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    //入参检查
    if(grid == NULL)
    {
        return 0;
    }

    //循环遍历矩阵中的各元素
    int num = 0;
    for(int i=0; i<gridSize;i++)
    {
        for(int j =0;j<(*gridColSize);j++)
        {
            if(grid[i][j] <0)
            {
                num++;
            }
        }
    }
    return num;
}
```
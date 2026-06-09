### 解题思路
该题直接通分实现，解题思路如下：
* 入参检查 
* 分配并初始化数组，**初始化数组的时候需要注意**
* 从后向前遍历数组，并通分实现
* 返回结果

**Note: 该题最简洁的解法应该是利用递归，但未成功实现。**

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize)
{
    //入参检查
    if(cont == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    //分配和初始化数组
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    result[0] = cont[contSize-1];
    result[1] = 1;

    //迭代计算
    for(int i=contSize-1;i>0;i--)
    {
        int tmp = result[0];
        result[0] = cont[i-1]*result[0]+result[1];
        result[1] = tmp;
    }

    //返回结果
    return result;
}
```
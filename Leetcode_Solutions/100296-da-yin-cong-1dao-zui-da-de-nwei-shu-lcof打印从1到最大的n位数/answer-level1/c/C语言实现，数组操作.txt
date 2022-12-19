### 解题思路
本题解法比较简单，思路如下：
1 求出n代表几位数，利用pow函数求解最大数值
2 数组需返回1~maxnum的数组，赋值时需注意。

Note：该程序中利用了pow，malloc和memset等系统调用函数，导致程序运行时间较长。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize)
{
    //先求位数
    int num = (int)pow(10,n);
    int len = num-1; //数组中不能打印0，因此returnSize的长度为num减去1

    //分配并初始化数组
    int *result = (int*)malloc(sizeof(int)* len);
    memset(result,0,sizeof(int)*len);

    //数组赋值
    for(int i =0; i<len;i++)
    {
        result[i] = i+1;
    }

    *returnSize = len;
    return result;

}
```
### 解题思路
该题运用暴力解法完成，解题思路如下：
* 入参检查
* 分配并初始化数组
* 循环遍历n，范围是1~n-1
* 利用**judgeZero**函数判断i和n-i两数中是否包含0
* 如果符合要求则返回i和n-i，否则继续循环

**Note：原打算在judgeZero函数中应用itoa库函数将n转化为字符串，然后判断是否有'0'字符。然而，leetcode不支持使用itoa，只能作罢。**

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool judgeZero(int n)
{
    while(n)
    {
        if(n%10 == 0)
        {
            return false;
        }
        n = n/10;
    }
    return true;
}

int* getNoZeroIntegers(int n, int* returnSize)
{
    //入参检查
    if(n == 0)
    {
        return NULL;
    }

    //分配并初始化数组
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*2);

    //循环判断从1~n-1，并返回第一组符合要求的数据
    for(int i = 1; i < n;i++)
    {
        if(judgeZero(i) && judgeZero(n-i))
        {
            result[0] = i;
            result[1] = n-i;
        }
    }
    return result;
}
```
### 解题思路

就是鸡兔同笼的变形。。。需要注意结果需要大于等于0。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
    int *ret;
    ret=(int *)malloc(sizeof(int)*2);
    *returnSize=0;
    if((4*cheeseSlices-tomatoSlices)%2==0)
    {
        ret[1]=(4*cheeseSlices-tomatoSlices)/2;
        ret[0]=cheeseSlices-ret[1];
        if(ret[1]>=0&&ret[0]>=0)
        {
            *returnSize=2;
        }
    }
    return ret;
}
```
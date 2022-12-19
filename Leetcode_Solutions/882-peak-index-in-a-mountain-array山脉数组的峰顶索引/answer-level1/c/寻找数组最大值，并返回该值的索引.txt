### 解题思路


### 代码

```c
int peakIndexInMountainArray(int* A, int ASize)
{
    //入参判断
    if(ASize < 3)
    {
        return 0;
    }
    //寻找数组的最大值
    int max = A[0];
    int index = 0;
    for(int i  =0; i < ASize; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
            index = i;
        }
    }
    return index;
}
```
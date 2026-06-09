### 解题思路

### 代码

```c
int smallestRangeI(int* A, int ASize, int K)
{
    int res,max = A[0],min = A[0];
    if(ASize == 1) return 0;
    for(int i = 0;i< ASize;++ i)
    {
        if(A[i] > max)  
        {
            max = A[i];
            continue;
        }
        else if(A[i] < min)     min = A[i];
    }
    if(max - min <= 2 * K)  return 0;
    else return max - min -2 * K;
    return 0;
}
```
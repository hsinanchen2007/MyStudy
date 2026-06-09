### 解题思路
官方解题思路
### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0,sum1=0;
    for(int i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3)
        return false;
    int i,j=0,i0=0;
    for(i=0;i<ASize;i++)
    {
        sum1+=A[i];
        if(sum1==sum/3)
        {
            i0=i;
            break;
        }
            
    }
    for(i=i0+1;i<ASize-1;i++)
    {
        sum1+=A[i];
        if(sum1==sum/3*2)
            return true;
    }
    return false;
}
```
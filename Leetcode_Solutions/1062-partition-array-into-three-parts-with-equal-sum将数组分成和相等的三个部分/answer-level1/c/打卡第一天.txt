### 解题思路
此处撰写解题思路

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){

    int sum=0;
    for(int i=0;i<ASize;i++)
    {
        sum+=A[i];
    }

    if(sum%3!=0)
    {
        return false;
    }

    int partsum=sum/3;
    int sum1=0;
    int i=0;
    for(;i<ASize-2;i++)
    {
        sum1+=A[i];
        if(sum1==partsum)
        {
            break;
        }
    }
    
    if(i==ASize-2)
    {
        return false;
    }

    int sum2=0;
    for(int j=ASize-1;j>i+1;j--)
    {
        sum2+=A[j];
        if(sum2==partsum)
        {
            return true;
        }
    }
    return false;

}
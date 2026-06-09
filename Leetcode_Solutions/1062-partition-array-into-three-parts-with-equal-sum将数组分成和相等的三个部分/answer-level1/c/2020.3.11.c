### 解题思路
首先将数组元素A[i]重新计算赋值为包括A[i]的i之前的元素总和和，满足条件的数组总和A[Asize-1]一定能被3整除，1/3总和记为x，可以将新的数组分成[0,i][i+1,j][j,Asize-1]三部分，符合条件的数组一定满足A[i]=x，A[j]=2*x,并且j>i,j<Asize-1,所以我们只需要找到最小的i和最大的j，满足j>i,就能判断数组可以满足条件

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    for(int i=1;i<ASize;i++)
    {
        A[i]+=A[i-1];
    }
    if(A[ASize-1]%3!=0)
    {
        return false;
    }
    int oneOfThreeSum=A[ASize-1]/3;
    int twoOfThreeSum=oneOfThreeSum*2;
    int min_i=50000;
    int max_j=0;
    for(int i=0;i<ASize-1;i++)
    {
        if(A[i]==oneOfThreeSum && min_i==50000)
        {
            min_i=i;
        }
        else if(A[i]==twoOfThreeSum)
        {
            max_j=i;
        }

        if(max_j>min_i)
        {
            return true;
        }
    }
    return false;
}
```
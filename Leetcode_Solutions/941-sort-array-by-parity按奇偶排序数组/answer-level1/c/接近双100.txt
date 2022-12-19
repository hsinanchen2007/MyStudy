### 解题思路
设置两个变量，指向开始和结尾。前一个变量遇到奇数时转而去判断后面的变量，如果是偶数，交换。如果是奇数，前移，直到遇到偶数。****这里面要注意加上判断条件，不然容易出错和导致数组越界，我认为这是关键。如果j==i，直接结束
****
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int i,j;
    int temp;
    for(i=0,j=ASize-1;i<j;i++)
    {
        if(A[i]%2==1)
        {

            while(A[j]%2==1&&j>i)
                j--;
            if(i==j)
                break;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            j--;
            // if(A[j]%2==1)
            //     j--;
            // else
            // {
            //     temp=A[i];
            //     A[i]=A[j];
            //     A[j]=temp;
            //     j--;
            // }
        }

    }
    int *a=(int *)malloc(sizeof(int)*ASize);
    for(i=0;i<ASize;i++)
    {
        a[i]=A[i];
    }
    *returnSize=ASize;

    return a;
}
```
### 解题思路
先排序，再一个个算差值

### 代码

```c
void quicksort(int *A,int start,int end)
{
    int mid=*(A+end);
    int left=start;
    int right=end-1;
    while(left<right)
    {
        while(*(A+left)<mid && left<right) left++;
        while(*(A+right)>=mid && left<right) right--;
        if(left<right)
        {
            int tmp;
            tmp=*(A+left);
            *(A+left)=*(A+right);
            *(A+right)=tmp;
            left++;
            right--;
        }
    }
    if(*(A+left)>mid)
    {
        *(A+end)=*(A+left);
        *(A+left)=mid;
    }
    if(left>start)
    {
        quicksort(A,start,left);
    }
    if(left<end-1)
    {
        quicksort(A,left+1,end);
    }
}

int minIncrementForUnique(int* A, int ASize){
    if(ASize<2) return 0;
    quicksort(A,0,ASize-1);
    int ans=0;
    int n=A[0];
    for(int i=1;i<ASize;i++)
    {
        if(A[i]<=n)
        {
            n++;
            ans+=n-A[i];
        }
        else
        {
            n=A[i];
        }
       // printf("%d ",A[i]);
    }
    return ans;
}
```
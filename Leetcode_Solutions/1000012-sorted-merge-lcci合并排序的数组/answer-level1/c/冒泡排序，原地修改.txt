```
void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    if(n==0)
        return;
    int j=0;
    //先将B移入A
    for(int i=m;i<m+n;i++)
    {
        A[i]=B[j++];
    }
    //冒泡排序
    for(int i=0;i<m+n-1;i++)
    {
        int flag=1;
        for(j=m+n-1;j>i;j--)
        {
            if(A[j]<A[j-1])
            {
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=0;
            }
            
        }
        if(flag)
            return;
    }

}
```

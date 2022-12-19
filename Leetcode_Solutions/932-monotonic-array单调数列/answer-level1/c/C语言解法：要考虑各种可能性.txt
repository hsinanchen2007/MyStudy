```
bool isMonotonic(int* A, int ASize)
{
    int i,j,n=ASize;
    int sign=0;
    if(ASize==1) return true;
    else
    {
        for(i=0;i<n-1;i++)
        {
            if(A[i+1]==A[i]) continue;
            else if(A[i+1]>A[i])
            {
                for(j=i;j<n-1;j++)
                {
                    if(A[j+1]>=A[j]) continue;
                    else return false;
                }
                return true;
            }
            else
            {
                for(j=i;j<n-1;j++)
                {
                    if(A[j+1]<=A[j]) continue;
                    else return false;
                }
                return true;
            }
        }
        return true;
    }
}
```

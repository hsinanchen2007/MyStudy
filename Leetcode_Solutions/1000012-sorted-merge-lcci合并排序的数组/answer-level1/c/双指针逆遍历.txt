### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    int b=m+n-1;
    m--;n--;
    for(b;b>=0;b--)
    {
        if(m>=0 && n>=0)
        {
            if(A[m]>=B[n])
              A[b]=A[m--];
            else 
              A[b]=B[n--];
        }
        else if(m>=0 && n<0)
          break;
        else if(m<0 && n>=0)
          A[b]=B[n--];
    }
}
```
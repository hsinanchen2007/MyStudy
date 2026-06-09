### 解题思路
正常思路从小到大一个个排列，开辟一个新数组，但是这样浪费了额外的空间，由于题目中说到A数组尾部有足够的空间，因此可以逆序排列，从大到小，不需要新的空间，时间O（n+m），空间1。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
int i=m-1,j=n-1,k=ASize-1;
while(i>=0&&j>=0)
{
    if(A[i]>B[j]) 
    {
        A[k]=A[i];
        i--;
        k--;
    }
    else{
        A[k]=B[j];
        j--;
        k--;
    }
}
while(i>=0)
{
        A[k]=A[i];
        i--;
        k--;
}
while(j>=0)
{
        A[k]=B[j];
        j--;
        k--;
}
}
```
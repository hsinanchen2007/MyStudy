### 解题思路
先确定A能被占用的长度，A和B的个数-1是最后可以存的最大位置，之后比较A和B的最大的值得大小，大的给A[max]位置，有消耗没的之后就循环赋值了。希望这样描述能说得清楚。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i=m-1;
    int j=n-1;
    int max=m+n-1;
   while(j>=0&&i>=0)
    {
        if(A[i]>=B[j])
        {
            A[max--]=A[i--];
        }
        else
        {
            A[max--]=B[j--];
        }
    }
    while(i>=0)
    {
        A[max--]=A[i--];
    }
    while(j>=0)
    {
        A[max--]=B[j--];
    }



}
```
### 解题思路
此处撰写解题思路

### 代码

```c
int min(int a,int b,int c){
    if (a < b)
    {
        return a < c?a:c;
    }
    else
    {
        return b < c?b:c;
    }
}
int nthUglyNumber(int n){
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int *arr = (int *)malloc(n*sizeof(int));
    arr[0] = 1;
    if (n == 0)
    {
        return 0;
    }
    for (int index = 1;index < n;index++)
    {
        arr[index] = min(2*arr[p1],3*arr[p2],5*arr[p3]);
        if (arr[index] == 2*arr[p1])
        {
            p1++;
        }
        if (arr[index] == 3*arr[p2])
        {
            p2++;
        }
        if (arr[index] == 5*arr[p3])
        {
            p3++;
        }
    }
    return arr[n-1];
}
```
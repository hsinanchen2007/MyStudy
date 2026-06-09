### 解题思路
时间复杂度O(m+n)
参数解释：
    i : A坐标
    j ：B坐标
    pos：lst坐标
    lst：数组
思路：
    首先，申请数组空间lst用于存储最终排序的结果
    然后，比较A[i],B[j]，把小的那一个存储在lst中，并且i++，pos++
    直至，i>m或者j>n，之后再把，A或者B剩余的元素存储在lst中
    最后，将lst中结果拷贝到A中

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int *lst=(int*)malloc(sizeof(int)*(m+n));
    int i=0,j=0;
    int pos=0;
    while(i<m&&j<n)
    {
        if(A[i]<=B[j])
        {
            lst[pos++]=A[i++];
        }
        else
        {
            lst[pos++]=B[j++];
        }
    }
    while(i<m)
    {
        lst[pos++]=A[i++];
    }
    while(j<n)
    {
        lst[pos++]=B[j++];
    }
    for(int i=0;i<m+n;i++)
    {
        A[i]=lst[i];
    }
    free(lst);
}
```
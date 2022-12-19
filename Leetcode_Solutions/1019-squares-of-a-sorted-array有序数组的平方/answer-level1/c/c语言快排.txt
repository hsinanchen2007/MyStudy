### 解题思路
利用快排函数解决不会写快排的烦恼，哈哈。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int f(int* a,int* b)
{
    return *a>*b?1:0;
}
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* num=(int*)malloc(sizeof(int)*ASize);
    for(int i=0;i<ASize;i++)
    num[i]=A[i]*A[i];
    qsort(num,ASize,sizeof(int),f);
    *returnSize=ASize;
    return num;
}
```
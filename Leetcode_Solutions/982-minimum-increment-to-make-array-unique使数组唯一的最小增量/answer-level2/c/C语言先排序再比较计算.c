### 解题思路
先做一个排序，这对于后续处理是很方便的。
排序后，进行遍历，如果不是递增，则将它加1直到变为递增即可。

C语言只知道库函数有qsort，不知道还有没有其他的排序库函数。

### 代码

```c
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int minIncrementForUnique(int* A, int ASize){
    int i, res=0;
    // 排序
    qsort(A, ASize, sizeof(int), cmpfunc);
    // 遍历并比较
    for(i=0; i<ASize-1; i++){
        if(A[i]>=A[i+1]){
            res += (A[i]-A[i+1]+1);
            A[i+1] = A[i] + 1;
        }
    }
    return res;
}

```
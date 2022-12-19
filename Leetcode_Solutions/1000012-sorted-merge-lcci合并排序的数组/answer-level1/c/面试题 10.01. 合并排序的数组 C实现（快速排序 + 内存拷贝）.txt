### 解题思路
此处撰写解题思路

### 代码

```c
int Cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    memcpy(&A[m], B, sizeof(int) * n);
    qsort(A, ASize, sizeof(int), Cmp);
    return;
}
```
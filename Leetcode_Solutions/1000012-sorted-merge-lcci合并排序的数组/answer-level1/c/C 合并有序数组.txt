解法一：内存拷贝后快速排序
```c []
int comp(const void*a, const void*b){
    return (*(int*)a - *(int*)b);
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    memcpy(&A[m],&B[0],sizeof(int)*n);
    qsort(A,m+n,sizeof(int),comp);
}
```
解法二：双指针 效率显然高于再排序的方法
```c []
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int back = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >=0) {
        if (A[m] > B[n])
            A[back--] = A[m--];
        else
            A[back--] = B[n--];
    }
    while (m >= 0)
        A[back--] = A[m--];
    while (n >= 0)
        A[back--] = B[n--];
}
```

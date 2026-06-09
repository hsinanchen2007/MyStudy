### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(int* a,int* b){
    return *a - *b;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = n;
    while(i--){
        A[m+i] = B[i];
    }
    qsort(A,(m+n),sizeof(int),cmp);
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int largestPerimeter(int* A, int ASize){
    int i, tmp;
    int sum = 0;

    qsort(A, ASize, sizeof(int), cmp);

    ASize = ASize - 2;
    for (i = 0; i < ASize; i++) {
        tmp = A[i + 1] + A[i + 2];
        if (A[i] < tmp) {
            sum = A[i] + tmp;
            break;
        }
    }

    return sum;
}
```
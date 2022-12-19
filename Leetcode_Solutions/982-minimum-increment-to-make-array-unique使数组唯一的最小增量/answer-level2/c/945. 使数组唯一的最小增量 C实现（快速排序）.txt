### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* A, int ASize){
    if (!A || ASize <= 0) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), cmp);
    int cnt = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i - 1] >= A[i]) {
            cnt += A[i - 1] - A[i] + 1;
            A[i] = A[i - 1] + 1;
        }
    }
    return cnt;
}
```
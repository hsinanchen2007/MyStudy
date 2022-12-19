### 解题思路
我只会查表。。。

### 代码

```c
#define MAX_NUM 50001

int comp(const void *arg1, const void *arg2) {
    int *a = (int *)arg1;
    int *b = (int *)arg2;
    return *a - *b;
}

int minIncrementForUnique(int* A, int ASize){
    int table[MAX_NUM];
    memset(table, 0, sizeof(int) * MAX_NUM);
    for (int i = 0; i < ASize; ++i) {
        table[A[i]]++;
    }
    qsort(A, ASize, sizeof(int), comp);

    int ans = 0;
    int start = 0;
    for (int i = 0; i < ASize; ++i) {
        if (table[A[i]] > 1) {
            if (start <= A[i]) {
                start = A[i] + 1;
            }
            while (table[start] != 0) {
                ++start;
            }
            ans += start - A[i];
            table[A[i]]--;
            table[start++]++;
        }
    }
    return ans;
}
```
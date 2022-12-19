### 解题思路
上代码

### 代码

```c
int minIncrementForUnique(int* A, int ASize){
    int* hash = (int *)malloc(sizeof(int) * 80000);
    memset(hash, 0, sizeof(int) * 80000);
    for (int i = 0;i < ASize; i++) {
        hash[A[i]]++;
    }
    int ret = 0;
    int taken = 0;
    for (int i = 0; i < 80000; i++) {
        if (hash[i] >= 2) {
            int current = hash[i] - 1;
            taken += current;
            ret -= i * current;
        } else if (taken > 0 && hash[i] == 0) {
            taken--;
            ret += i;
        }
    }
    free(hash);
    return ret;
}
```
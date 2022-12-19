### 解题思路
此处撰写解题思路

### 代码

```c
inline char GetAndRemoveAtIndex(int* nums, int idx, int idxLim)
{
    int ret = nums[idx] + '0';
    if (idx < idxLim) {
        memmove(&nums[idx], &nums[idx + 1], sizeof(int) * (idxLim - idx));
    }
    return ret;
}

char * getPermutation(int n, int k){
    if (n <= 0 || k <= 0) {
        return NULL;
    }
    int* factories = (int*)malloc(sizeof(int) * n);
    factories[0] = 1;
    int* nums = (int*)malloc(sizeof(int) * n);
    nums[0] = 1;
    for (int i = 1; i < n; i++) {
        nums[i] = i + 1;
        factories[i] = i * factories[i - 1];
    }
    char* s = (char*)malloc(sizeof(char) * (n + 1));
    int k1 = k - 1;
    int idxLim = n - 1;
    int idx;
    for (int i = 0; i < n; i++) {
        idx = k1 / factories[idxLim - i];
        s[i] = GetAndRemoveAtIndex(nums, idx, idxLim);
        k1 %= factories[idxLim - i];
    }
    free(factories);
    free(nums);
    s[n] = '\0';
    return s;
}


```
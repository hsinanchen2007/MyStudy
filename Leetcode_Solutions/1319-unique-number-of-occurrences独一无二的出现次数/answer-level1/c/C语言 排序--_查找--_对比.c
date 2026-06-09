### 解题思路
此处撰写解题思路

### 代码

```c
int Com(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool uniqueOccurrences(int* arr, int arrSize){
    if (arrSize == 1) {
        return true;
    }
    int nums[1000] = {0};
    int len = 0;

    qsort(arr, arrSize, sizeof(int), Com);

    int tmp = 0;
    int i = 1;
    for (; i < arrSize; i++) {
        if (arr[i] != arr[i - 1]) {
            nums[len++] = i - tmp;
            tmp = i;
        }
    }
    nums[len++] = i - tmp;

    if (len == 1) {
        return true;
    }

    for (int j = 0; j < len - 1; j++) {
        for (int k = j + 1; k < len; k++) {
            if (nums[j] == nums[k]) {
                return false;
            }
        }
    }

    return true;
}
```
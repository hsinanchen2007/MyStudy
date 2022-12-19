C语言桶排序的解题思路。
对于每一个桶内的排序，没有做好动态排序，最终使用了qsort来排序，这里没有处理好，后续改改这块的代码。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BULK_SIZE 31
#define NUM_SIZE 501

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) {
        return 1;
    } else if (*(int*)a < *(int*)b) {
        return -1;
    }
    return 0;
}

int getBitNum(int n)
{
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){

    int bulk[BULK_SIZE][NUM_SIZE];
    int index[BULK_SIZE] = {0};
    int count;
    int* res = (int*)malloc(sizeof(int) * arrSize);

    memset((int*)&bulk[0][0], 0, sizeof(int) * BULK_SIZE * NUM_SIZE);

    for (int i = 0; i < arrSize; i++) {
        count = getBitNum(arr[i]);
        bulk[count][index[count]++] = arr[i];
    }

    for (int i = 0; i < BULK_SIZE; i++) {
        if (index[i] > 0) {
            qsort(&bulk[i][0], index[i], sizeof(int), compare);
        }
    }

    count = 0;
    for (int i = 0; i < BULK_SIZE; i++) {
        for (int j = 0; j < index[i]; j++) {
            res[count++] = bulk[i][j];
        }
    }

    *returnSize = arrSize;
    return res;

}
```

![image.png](https://pic.leetcode-cn.com/43c6ef2c080296766a0956172223d4d2d669e0401aa0096977d0c19ffc62ea21-image.png)

桶排序，感觉不像中等题。
```
#define DATA_SIZE 100001
int g_hashMap[DATA_SIZE];

int* sortArray(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int index;

    memset(g_hashMap, 0, sizeof(int) * DATA_SIZE);

    for (int i = 0; i < numsSize; i++) {
        g_hashMap[nums[i] + 50000]++;
    }

    index = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        while (g_hashMap[i] > 0) {
            res[index++] = i - 50000;
            g_hashMap[i]--;
        }
    }

    *returnSize = numsSize;
    return res;
}
```

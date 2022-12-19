### 解题思路
C 哈希 
数据元素为key 次数为value

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int* numsReturn = (int*)malloc(sizeof(int) * 2);
    memset(numsReturn, 0, sizeof(int) * 2);

    int* hashArray = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(hashArray, 0, sizeof(int) * (numsSize + 1));

    for(int i = 0; i < numsSize; i++) {
        hashArray[nums[i]]++;
    }
    for (int j = 1; j <= numsSize; j++) {
        if (hashArray[j] == 2) {
            *numsReturn = j;
        }
        if (hashArray[j] == 0) {
            *(numsReturn + 1) = j;
        }
    }
    return numsReturn;
}
```
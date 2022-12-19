### 解题思路
两个数组连起来，模拟连续数组
只需处理最大元素，即循环次数=2倍原数组长度-（下标+1）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    int *tmp = (int *)malloc(sizeof(int) * numsSize * 2);
    memset(ret, 0, sizeof(int) * numsSize);
    memcpy(tmp, nums, sizeof(int) * numsSize);
    memcpy(tmp + numsSize, nums, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = i + 1; j < 2 * numsSize; j++) {
            count++;
            if (tmp[j] > nums[i]) {
                ret[i] = tmp[j];
                break;
            }
        }
        if (count == 2 * numsSize - i - 1) {
            ret[i] = -1;
        }
    }
    *returnSize = numsSize;
    return ret;
}
```
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int low = 0, high = numbersSize - 1;

    // 看了很多题解都是在进入while循环之前就 malloc 内存了
    // 后面返回 NULL 的时候又没有释放，造成了内存泄露
    while (low < high) {
        if (numbers[low] + numbers[high] > target) {
            --high;
        } else if (numbers[low] + numbers[high] < target) {
            ++low;
        } else {
            // 应该在找到的时候分配内存，避免内存泄露
            int *ans = (int *) calloc(2, sizeof(int));
            ans[0] = low + 1;
            ans[1] = high + 1;
            *returnSize = 2;
            return ans;
        }
    }

    *returnSize = 0;
    return NULL;
}
```

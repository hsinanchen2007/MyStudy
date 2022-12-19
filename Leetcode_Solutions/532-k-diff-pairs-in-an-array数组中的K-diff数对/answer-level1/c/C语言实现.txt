先排序，然后逐个遍历每一个不同值的元素，搜索下一个与之配对的元素。
```C []
int cmp(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int findPairs(int* nums, int numsSize, int k){
    if (numsSize < 2 || k < 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, j, curr, count = 0, prev = 0x80000000;
    for (i = 0; i < numsSize - 1; ++i){
        if (nums[i] != prev) {
            prev = nums[i];
            curr = nums[i] - k;
            for (j = i + 1; j < numsSize && nums[j] >= curr; ++j) {
                if (nums[j] == curr) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}
```

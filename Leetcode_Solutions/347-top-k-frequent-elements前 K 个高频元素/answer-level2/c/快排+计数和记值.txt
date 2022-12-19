### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct stu {
    int count;
    int val;
};
void *comp(const void* a, const void *b) {
    return *(int *)a - *(int *)b;
}
void *compstru(const void* a, const void *b) {
    struct stu *aa = (struct stu *)a;
    struct stu *bb = (struct stu *)b;
    return (aa->count) - (bb->count);
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    qsort(nums, numsSize, sizeof(int), comp);
    struct stu freq[numsSize];
    int *retarr = (int *)malloc(sizeof(int) * k);
    int index = 0;
    *returnSize = k;
    freq[index].val = nums[0];
    freq[index].count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            index++;
            freq[index].val = nums[i];
            freq[index].count = 1;
        } else {
            (freq[index].count)++;
        }
    }
    /*
    for (int i = 0; i <= index; i++) {
        printf("fre[%d].val is %d, fre[%d].count is %d\n", i, freq[i].val, i, freq[i].count);
    } */
   // printf("index is %d\n", index);
    qsort(freq, index + 1, sizeof(struct stu), compstru);
    /*
    for (int i = 0; i <= index; i++) {
        printf("fre[%d].val is %d, fre[%d].count is %d\n", i, freq[i].val, i, freq[i].count);
    }
    printf("--------------\n");
    */
    for (int i = index; i > index - k; i--) {
        retarr[index - i] = freq[i].val;
      //  printf("fre[%d].val is %d, fre[%d].count is %d\n", i, freq[i].val, i, freq[i].count);
    }
    return retarr;
}
```
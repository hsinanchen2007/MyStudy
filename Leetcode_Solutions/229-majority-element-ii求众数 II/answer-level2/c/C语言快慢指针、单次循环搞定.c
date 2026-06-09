```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* p, const void* q)
{
    return (*(int*)p - *(int*)q) ;
}

int* majorityElement(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int i, j = 0;
    int sum;
    int index = 0;

    for(i = 0; i < numsSize; i = j) {
        sum = 1;
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] == nums[j]) {
                sum++;
            } else {
                break;
            }
        }
        if(sum > (numsSize / 3)) {
            nums[index] = nums[i];
            index++;
        }
    }

    int* ret = (int*)malloc(sizeof(int) * index);
    for(i = 0; i < index; i++) {
        ret[i] = nums[i];
    }

    *returnSize = index;
    return ret;
}
```

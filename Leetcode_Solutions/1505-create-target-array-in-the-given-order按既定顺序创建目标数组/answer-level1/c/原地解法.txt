可能有强迫症，每次都想尽可能的原地求解。。。
这道题原地求解的关键是提示明确写着 **0 <= index[i] <= i**

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    *returnSize = indexSize;

    for (int i = 0; i < indexSize; ++i) {
        if (index[i] < i) {
            int temp = nums[i];
            for (int j = i; j > index[i]; --j) {
                nums[j] = nums[j - 1];
            }
            nums[index[i]] = temp;
        }
    }

    return nums;
}
```

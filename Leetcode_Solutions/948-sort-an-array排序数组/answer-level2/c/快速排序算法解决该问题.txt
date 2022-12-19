### 解题思路
1 快速排序算法；
2 从右向左查找；
3 当相遇时交换两个数在数组中的位置；
4 最终将基准数归位；

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quicksort(int *output, int numsSize, int left, int right)
{
    int i, j, t, tmp;
    if (left > right) {
        return;
    } 
    tmp = output[left];
    i = left;
    j = right;
    while (i != j) {
        while (output[j] >= tmp && i < j) {
            j--;
        }
        while (output[i] <= tmp && i < j) {
            i++;
        }
        if (i < j) {
            t = output[i];
            output[i] = output[j];
            output[j] = t;
        }
    }
    output[left] = output[i];
    output[i] = tmp;
    quicksort(output, numsSize, left, i - 1);
    quicksort(output, numsSize, i + 1, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int i;
    *returnSize = numsSize;
    int *output = malloc((*returnSize) * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        output[i] = nums[i];
    }
    quicksort(output, *returnSize, 0, *returnSize - 1);

    return output;
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
/* 排序做法, O(nlogn) */
// int cmp(void *a, void *b)
// {
//     return *(int*)a - *(int*)b;
// }

// int majorityElement(int* nums, int numsSize)
// {
//     qsort(nums, numsSize, sizeof(nums[0]), cmp);
//     return nums[numsSize / 2];
// }

/* 这个方法 咋这么慢 */
// bool compare(int *nums, int numsSize, int target)
// {
//     int count = 0;
//     int i;
//     for (i = 0; i < numsSize; i++) {
//         if (nums[i] == target) {
//             count++;
//         }
//         if (count > numsSize / 2) {
//             return true;
//         }
//     }
//     return false;
// }

// int majorityElement(int* nums, int numsSize)
// {
//     if (compare(nums, numsSize, nums[numsSize / 2])) {
//         return nums[numsSize / 2];
//     }

//     if (compare(nums, numsSize, nums[numsSize / 2 + 1])) {
//         return nums[numsSize / 2 + 1];
//     }

//     if (compare(nums, numsSize, nums[numsSize / 4])) {
//         return nums[numsSize / 4];
//     }

//     if (compare(nums, numsSize, nums[numsSize / 4 + 1])) {
//         return nums[numsSize / 4 + 1];
//     }

//     if (compare(nums, numsSize, nums[numsSize * 3 / 4])) {
//         return nums[numsSize * 3 / 4];
//     }

//     if (compare(nums, numsSize, nums[numsSize * 3 / 4 + 1])) {
//         return nums[numsSize * 3 / 4 + 1];
//     }

//     return -1;
// }

/* 看到的一个牛逼的方法 记录下 */
int majorityElement(int* nums, int numsSize)
{
    int count;
    int i;
    int result = nums[0];
    for (i = 0; i < numsSize; i++) {
        if (result == nums[i]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            result = nums[i+1];
        }
    }

    return result;
}


```
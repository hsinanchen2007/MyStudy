### 解题思路
此处撰写解题思路

获取上边界，获取下边界。
参照二分法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int CheckParam(int* nums, int numsSize, int* returnSize)
{
    if (nums == NULL || numsSize < 0 || returnSize == NULL) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }

        return -1;
    }

    return 0;
}

int *ResultInit(int numsSize, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    if (ret == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 2;
    ret[0] = -1;
    ret[1] = -1;

    return ret;
}

int GetRightBound(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);

        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == numsSize - 1 || nums[mid + 1] > target) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}

int GetLeftBound(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0 || nums[mid - 1] < target) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    if (CheckParam(nums, numsSize, returnSize)) {
        return NULL;
    }

    int *ret = ResultInit(numsSize, returnSize);
    if (ret == NULL) {
        return NULL;
    }

    if (numsSize > 0) {
        ret[0] = GetLeftBound(nums, numsSize, target);
        ret[1] = GetRightBound(nums, numsSize, target);
    }
    
    return ret;
}

```
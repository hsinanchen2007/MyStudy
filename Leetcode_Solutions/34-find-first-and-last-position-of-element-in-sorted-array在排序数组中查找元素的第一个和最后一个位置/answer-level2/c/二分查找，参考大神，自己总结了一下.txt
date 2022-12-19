```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    res[0] = -1;
    res[1] = -1;

    //二分查找算法必须在n >1 的场景下才能正常运行，否则会出现越界访问
    if (numsSize == 1) {
        if (nums[0] == target) {
            res[0] = 0;
            res[1] = 0;
        }
        return res;
    }

    int left = 0;
    int right = numsSize; //[left, right) 左闭右开的搜索区间

    //寻找左边界
    while (left < right) { //左闭右开的搜索区间，终止条件是left == right，即区间变成[left, left)时，区间已空，所以这里使用小于号
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid; //继续向左搜索，区间保持左闭右开，mid已被搜索过了，所以right == mid时，mid不会再被搜索，区间依然是左闭右开
        } else if (nums[mid] < target) {
            left = mid + 1; //向右搜索，为了保持区间左闭右开，left = mid + 1，可以保证左闭
        } else if (nums[mid] > target) {
            right = mid; //向左搜索，right = mid，可以保证右开。
        }
    }
    //二分查找算法运行完成后left中保存的是搜索结果，这里left保存的是左边界，因为左边界是闭合的，
    //而numsSize是越界下标，所以left == numsSize时越界
    if (left == numsSize) {
        res[0] = -1;
        res[1] = -1;
        return res;
    } else {
        res[0] = left;
    }

    //寻找右边界
    left = 0;
    right = numsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1; //保证新的搜索区间也是左闭的
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    //二分查找算法运行完成后left中保存的是搜索结果，这里left保存的是右边界，因为右边界是开放的，
    //所以left == numsSize时并不超出区间，left - 1 等于 nusSize时才算超出搜索区间
    if (left - 1 == numsSize) {
        res[0] = -1;
        res[1] = -1;
        return res;
    } else {
        res[1] = left - 1;
    }

    if (res[0] > res[1]) {
        res[0] = -1;
        res[1] = -1;
    }

    return res;
}
```

解题思路：采用双指针，left从数组0号元素开始，right从数组最后一个元素开始，一次循环操作left和right指针，如果left对应的元素比target小（nums[left] < target），left增加；如果right对应的元素比target大（nums[right] > target），right减少；如果nums[left]等于target，且nums[right]等于target循环结束; 如果left等于right结束循环。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0;
    int right = numsSize - 1;
    int *result = NULL;

    result = malloc(2 * sizeof(int));

    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;

    while (left <= right) {
        if(nums[left] == target && nums[right] == target) {
            result[0] = left;
            result[1] = right;
            return result;
        } else if (nums[left] < target) {
            left++;
        } else if (nums[right] > target) {
            right--;
        }
    }

    return result;
}

```
int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    // printf("target = %d\n", target);
    if (numsSize == 0) {
        return -1;
    }

    while (left <= right && left >= 0) {
        // printf("left = %d\n", left);
        // printf("right = %d\n", right);
        if (nums[left] == target) {
            return left;
        }

        if (nums[right] == target) {
            return right;
        }

        mid = (left + right) / 2;
        // printf("mid = %d\n", mid);

        if (left == mid) {
            break;
        } 

        // 左边是严格保序的
        if (nums[left] < nums[mid]) {
            // 因为是闭合区间，所新的要在区间里
            if ((target >= nums[left]) && (target <= nums[mid])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else { // 右边是保序
            // 闭合区间要在里面
            if ((target >= nums[mid]) && (target <= nums[right])) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        // printf("=========================\n");
    }
    // printf("mid = %d\n", mid);
    // printf("nums[mid] = %d\n", nums[mid]);
    return nums[mid] == target ? mid : -1;
}
```

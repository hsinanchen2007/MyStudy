### 解题思路
此处撰写解题思路

注意：临界条件，left <= right；初始调试，left = 0, right = len - 1, mid = (left + right) / 2;

### 代码

```c
int search(int* nums, int numsSize, int target){
    int left, right, mid;

    if (nums == NULL || numsSize <= 0) {
        return -1;
    }

    left = 0;
    right = numsSize - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] <= nums[mid]) { // 左边有序
            if (target >= nums[left] && target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
```
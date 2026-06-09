### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/22f9bb81643394b0ca5ce95a63f0b17cfe50da9ea3d62a019fe395b982d24ec5-image.png)

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (mid + 1 < numsSize && nums[mid] < target) {
            left = mid + 1;
        }

        if (mid + 1 == numsSize && nums[mid] < target) {
            return numsSize;
        }

        if (mid >= 1 && nums[mid] > target) {
            right = mid - 1;
        }

        if (mid == 0 && nums[mid] > target) {
            return 0;
        }
    }

    if (nums[left] < target) {
        return left + 1;
    }
    return left;
}
```
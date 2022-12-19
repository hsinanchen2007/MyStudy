![5819AD4B-8CE5-4B31-9546-ED671FF09F84.jpeg](https://pic.leetcode-cn.com/7398b91da1c69c67f2483b44a031626f57902fc631ea9eb0f1a7c989eef79607-5819AD4B-8CE5-4B31-9546-ED671FF09F84.jpeg)

```
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle = 0;

    if (nums == NULL) {
        return 0;
    }
    if (nums[0] > target) {
        return 0;
    }
    if (nums[numsSize - 1] < target) {
        return numsSize;
    }

    while (left < right) {
        middle = left + (right - left) / 2;
        //printf("left: %d, right: %d,middle: %d\n",left, right, middle);
        if (nums[middle] == target) {
            return middle;
        }
        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}
```

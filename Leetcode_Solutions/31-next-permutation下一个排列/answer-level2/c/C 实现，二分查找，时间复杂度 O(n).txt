![2019-10-03_20-51.png](https://pic.leetcode-cn.com/4914481579a813121b0a8085d20dba6ecac0baf11e26c6e2441a5ac9e94d918c-2019-10-03_20-51.png)

```c
// 从倒序列表中找出比 target 大的第一个元素
int findIndex(int * nums, int start, int end, int target) {
    // 二分法中点
    int mid = start;
    while (end > start) {
        mid = (start + end) >> 1;
        // start == mid 时只剩 1 个元素
        if (start == mid)
            return target < nums[end]? end: mid;
        else if (nums[mid] > target)
            start = mid;
        else
            end = mid;
    }
    return mid;
}

// 对 nums 数组的 start 到 end 做倒序排列
void reverse(int * nums, int start, int end) {
    nums += start;
    end -= start;
    int tmp;
    for (int i = 0; i < (end >> 1); i++) {
        tmp = nums[i];
        nums[i] = nums[end - i - 1];
        nums[end - i - 1] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize){
    int index = -1;    // 记录第一个下降点的索引
    // 从后往前遍历，直到遇到 nums[i - 1] < nums[i]，记录 index
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    // 当 index == -1，说明没有下降点，直接对全数组做反转
    if (index == -1) {
        reverse(nums, 0, numsSize);
        return;
    }
    // 获取待交换的索引
    int swap = findIndex(nums, index + 1, numsSize - 1, nums[index]);
    int tmp = nums[index];
    nums[index] = nums[swap];
    nums[swap] = tmp;
    reverse(nums, index + 1, numsSize);
}
```
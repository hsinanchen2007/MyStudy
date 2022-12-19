## 双指针 一次遍历

- 时间复杂度：O(N), 一次循环搞定
- 空间复杂度：O(1), 两个临时变量
```
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    if (!nums || nums.length === 0) {
        return 0
    }

    let slow = 0;

    for (let fast = 0; fast < nums.length; fast++) {
        if (nums[fast] === val) continue;
        nums[slow] = nums[fast]; // 此处可以加 slow !== fast && (...)
        slow += 1;
    }

    return slow;
};
```

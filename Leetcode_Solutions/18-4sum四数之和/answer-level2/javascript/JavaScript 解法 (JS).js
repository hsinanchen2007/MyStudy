>执行用时 :132 ms, 在所有 JavaScript 提交中击败了97.70%的用户

解法与三数之和思路相同，唯一不同时多一层循环，固定两位数字，用双指针寻找第三位及第四位数字。

```JavaScript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    if (nums.length < 4) {
        return [];
    }
    nums.sort((a, b) => a - b);
    const result = [];
    for (let i = 0; i < nums.length - 3; i++) {
        // 若与已遍历过的数字相同，避免结果中出现重复的数组
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        // 若当前循环的前四位数字已大于 target
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        for (let j = i + 1; j < nums.length - 2; j++) {
            // 若与已遍历过的数字相同，避免结果中出现重复的数组
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            let left = j + 1,
                right = nums.length - 1;
            while (left < right) {
                const sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum === target) {
                    result.push([nums[i], nums[j], nums[left], nums[right]]);
                }
                if (sum <= target) {
                    while (nums[left] === nums[++left]);
                } else {
                    while (nums[right] === nums[--right]);
                }
            }
        }
    }
    return result;
};
```
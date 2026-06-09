### 解题思路
第一种使用循环配合 `indexOf` 解决，复杂度应该在 `O(n)` 到 `O(n^2)` 之间

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const len = nums.length;

    for (let i = 0; i < len; i ++) {
        const cur = nums[i];
        const remain = target - cur;
        const reIdx = nums.indexOf(remain);

        if (reIdx > -1 && reIdx !== i) {
            return [i, reIdx]
        }
    }
};
```

第二种使用 `map` 解法，复杂度是 `O(n)`

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const len = nums.length;
    const m = new Map();

    for (let i = 0; i < len; i ++) {
        const remain = target - nums[i];
        if (m.has(remain) && m.get(remain) !== i) {
            return [i, m.get(remain)];
        } else {
            m.set(nums[i], i);
        }
    }
};
```
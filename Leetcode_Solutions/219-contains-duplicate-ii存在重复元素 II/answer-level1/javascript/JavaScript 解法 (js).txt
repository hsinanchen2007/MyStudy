用`Map`保存当前的元素作为`key`，其索引作为`value`，当遇到`map.get(key)`与当前索引相差小于等于`k`即返回`true`。
>执行用时 :84 ms, 在所有 JavaScript 提交中击败了97.88%的用户

```JavaScript
var containsNearbyDuplicate = function (nums, k) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i]) && i - map.get(nums[i]) <= k) {
            return true;
        } else {
            map.set(nums[i], i);
        }
    }
    return false;
};
```
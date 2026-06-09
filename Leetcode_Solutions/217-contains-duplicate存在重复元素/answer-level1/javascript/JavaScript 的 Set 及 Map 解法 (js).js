首先为最为偷懒的`Set`解法，利用了`Set`自动去重的原理。
>执行用时 :88 ms, 在所有 JavaScript 提交中击败了95.60%的用户
```JavaScript
var containsDuplicate = function (nums) {
    return new Set(nums).size < nums.length;
};
```

其次为`Map`解法，在`for`循环中存储当前的值作为`Map`的`key`，当遇到`Map.has(key)`为`true`时，代表有重复值。
>执行用时 :108 ms, 在所有 JavaScript 提交中击败了78.06%的用户
```JavaScript
var containsDuplicate = function (nums) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            return true;
        } else {
            map.set(nums[i], 1);
        }
    }
    return false;
};
```
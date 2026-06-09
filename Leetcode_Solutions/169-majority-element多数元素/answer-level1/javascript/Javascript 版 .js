> 执行用时 :80 ms, 在所有 JavaScript 提交中击败了98.19%的用户

这里使用了 `Map` 来存储遍历时的数字，以数字作为`key`，以重复次数为`value`，当我们`map.get(key)`存在时，便将其值加1，否则插入新的数字，并将其值设为1。

```Javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    if (nums.length === 1) {
        return nums[0];
    }
    const map = new Map();
    for (let num of nums) {
        if (!map.get(num)) {
            map.set(num, 1);
        } else {
            map.set(num, map.get(num) + 1);
            if (map.get(num) > nums.length / 2) {
                return num;
            }
        }
    }
};
```
哈希
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const record = {};
    for (let i of nums) {
        if (record[i]) return i;
        else record[i] = 1;
    }
};
```

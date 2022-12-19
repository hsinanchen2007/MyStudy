```js
var thirdMax = function(nums) {
    nums.sort((a, b) => b - a);
    let unique = [...new Set(nums)]
    return unique[2] === undefined ? unique[0] : unique[2]
};
```
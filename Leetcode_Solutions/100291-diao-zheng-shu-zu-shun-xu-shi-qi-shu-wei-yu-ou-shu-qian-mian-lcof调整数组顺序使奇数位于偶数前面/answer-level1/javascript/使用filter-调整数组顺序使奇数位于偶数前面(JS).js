```js
var exchange = function(nums) {
    let odd = nums.filter(cur => cur%2 === 1);
    let even = nums.filter(cur => cur%2 === 0);
    return odd.concat(even);
};
```
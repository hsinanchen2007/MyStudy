无论有多少正数或者负数,首先一定会选择最大数即nums[n-1],然后无非就是选择开头两位还是倒数两位

```js
var maximumProduct = function(nums) {
    nums.sort((a, b) => a - b);
    let len = nums.length;
    let product1 = nums[len-1] * nums[0] * nums[1];
    let product2 = nums[len-1] * nums[len-2] * nums[len-3];
    return Math.max(product1,product2);
};
```


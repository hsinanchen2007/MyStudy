```js
var missingNumber = function(nums) {
    for(let i = 0; i <= nums.length; i++) {
        if(nums.indexOf(i) === -1) return i;
    }
};
```

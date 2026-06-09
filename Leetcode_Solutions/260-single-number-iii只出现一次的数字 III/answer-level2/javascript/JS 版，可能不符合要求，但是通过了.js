

```js
var singleNumber = function(nums) {
   nums.sort((a, b) => a - b);
   for(var pre, len = nums.length, i = 0; i < len; i++){
       if(nums[i] === nums[i + 1]) i++;
       else if(typeof pre !== 'undefined') return [pre, nums[i]];
       else pre = nums[i];
   }
};
```

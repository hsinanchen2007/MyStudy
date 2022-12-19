### 代码

```javascript
var missingNumber = function(nums) {
   let s = (0 + nums.length + 1) * (nums.length + 1 - 1) / 2;
   let sum = nums.reduce((prev, next) => {
       return prev + next
   })
   return s - sum 
};
```
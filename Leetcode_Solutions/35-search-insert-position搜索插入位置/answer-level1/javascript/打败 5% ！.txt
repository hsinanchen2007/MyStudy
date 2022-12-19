```javascript
var searchInsert = function(nums, target) {
    nums.push(target);
    nums.sort((a,b)=> a -b);
    return nums.indexOf(target)
};
```
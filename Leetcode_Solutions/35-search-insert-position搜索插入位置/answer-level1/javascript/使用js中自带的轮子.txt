js一行代码，可能这么做没啥意义。
```js
var searchInsert = function(nums, target) {
  return [...nums, target].sort((a, b) => a - b).indexOf(target); 
};
```

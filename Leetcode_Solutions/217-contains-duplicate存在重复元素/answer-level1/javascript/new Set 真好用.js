一般数组去重, 首选 new Set()
```js
var containsDuplicate = function(nums) {
	let filtOut = [...new Set(nums)];
	return filtOut.length === nums.length ? false : true;
};
```

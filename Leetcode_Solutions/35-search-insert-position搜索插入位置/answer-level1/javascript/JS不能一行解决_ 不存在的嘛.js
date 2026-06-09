python、C++能够一行解决，JS也可以的...

疯狂选择，(强行)一行解决

```
var searchInsert = function(nums, target) {
    return (nums.indexOf(target) !== -1? nums.indexOf(target): nums.findIndex(n => n > target)) !== -1? (nums.indexOf(target) !== -1? nums.indexOf(target): nums.findIndex(n => n > target)): nums.length
};
```
![Snap1.jpg](https://pic.leetcode-cn.com/3fff760fb88440ac88dd4fb8ae76ad438d7440153f4ef93208fdfc7a792c8496-Snap1.jpg)


当然正常的写法可以如下：
```
var searchInsert = function(nums, target) {
    const n = nums.indexOf(target);
    const m = n !== -1? n: nums.findIndex(n => n > target);
    return m !== -1? m: nums.length
};
```

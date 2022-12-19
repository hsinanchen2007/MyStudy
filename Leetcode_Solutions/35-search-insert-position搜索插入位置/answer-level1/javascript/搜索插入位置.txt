*法一：挨个儿比对*

```js
var searchInsert = function(nums, target) {
    var len = nums.length;
    if (len === 0) {
        return 0;
    }
    for (var i = 0; i < len; i++) {
        if(nums[i] >= target) {
            return i;
        }
    }
    if (target > nums[len-1]) {
        return len;
    }
};

var nums = [1,3,5,6];
var target = 0;
console.log(searchInsert(nums, target))
```

*法二：二分查找*

待添加。。。
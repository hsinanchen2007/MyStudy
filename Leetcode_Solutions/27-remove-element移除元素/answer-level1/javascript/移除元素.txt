*法一：splice方法*
```js
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    var len = nums.length;
    for (var i = len - 1; i >= 0; i--) {
        if (nums[i] === val) {
            nums.splice(i,1)
        }
    }
    return nums.length;
};
var nums = [0,1,2,2,3,0,4,2];
var val = 2;
console.log(removeElement(nums, val))
```

*法二：直接修改数组*

```js
var removeElement2 = function(nums, val) {
    var len = nums.length;
    var index = 0;
    for (var i = 0; i < len; i++) {
        if (nums[i] !== val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
};
console.log(removeElement2(nums, val))
```

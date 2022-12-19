第一种是自己的做法，使用了 `js arrary` 的 `splice` 方法:

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        let j = i + 1;
        while (nums[i] === nums[j]) {
            nums.splice(j, 1);
        }
    }
    return nums.length;
};
```

第二种是参考了答案后使用双指针。双指针的方法初看不能理解，其实按照最原始的解法，创建一个新的数组，当遇到旧数组的指针与当前数值指针值不一致时，赋值给新的数组。双指针的方法是巧妙的用一个数组代替了两个数组赋值的方式。

```javascript
var removeDuplicates2 = function (nums) {
    if (nums.length === 0) {
        return 0;
    }
    let j = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
};
```
>执行用时 :88 ms, 在所有 JavaScript 提交中击败了89.14%的用户

初始化一个`[-Infinity, -Infinity, -Infinity]`数组，通过比较当前值与数组前三的值，并用`splice`方法来插入合适位置。最后根据结果长度返回第三值`arr[2]`或者最大值`arr[0]`。

```JavaScript
var thirdMax = function (nums) {
    if (nums.length < 3) {
        return Math.max(...nums);
    }
    let arr = [-Infinity, -Infinity, -Infinity];
    for (let i = 0; i < nums.length; i++) {
        if (arr.indexOf(nums[i]) > -1) {
            continue;
        }
        if (nums[i] > arr[0]) {
            arr.splice(0, 0, nums[i]);
        } else if (nums[i] > arr[1]) {
            arr.splice(1, 0, nums[i]);
        } else if (nums[i] > arr[2]) {
            arr.splice(2, 0, nums[i]);
        }
    }
    arr = arr.filter(item => item > -Infinity);
    return arr.length >= 3 ? arr[2] : arr[0];
};
```
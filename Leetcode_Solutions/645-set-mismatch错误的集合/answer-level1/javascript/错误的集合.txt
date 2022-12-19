利用Map对象求出重复数repeat,
丢失的数字 = [1,2..n] 正确数组的和 `rightSum` - （错误数组[1,2,m,m...n]的和 `wrongSum` - 重复数 `repeat` ）
```js
var findErrorNums = function(nums) {
    let len = nums.length;
    let repeat;
    let lost;
    let map = new Map();
    let wrongSum = 0;
    let rightSum = (1 + len ) * len / 2;
    for (let i = 0; i < len; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], true)
        } else {
            repeat = nums[i]
        }
        wrongSum += nums[i]
    }
    lost = rightSum - (wrongSum-repeat);
    return [repeat, lost];
};
```

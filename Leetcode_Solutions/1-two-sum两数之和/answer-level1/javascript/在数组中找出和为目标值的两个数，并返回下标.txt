### 解题思路
数组中的两个数之和等于目标值target，
即，target - arr[i] = arr[n];
循环数组，记录num = target - arr[i];
若数组中存在num则证明有两数之和等于目标值。并将i，push到空数组中。
nums.indexOf(num)可返回num在数组中所在的下标，一并push到空数组中，
最后将空数组返回即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const len = nums.length;
    var indexArr = []; // 存放两个指的下标
    let num; // 记录target 和数组元素的差
    for (var i = 0; i < len; i++) {
        num = target - nums[i];
        if (nums.indexOf(num, i + 1) >= 0) {
            indexArr.push(i);
            indexArr.push(nums.indexOf(num, i + 1));
            break;
        }
    }
    return indexArr
};
```
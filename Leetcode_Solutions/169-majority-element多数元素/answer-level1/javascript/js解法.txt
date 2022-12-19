### 解题思路
第一遍读题没看懂`⌊ n/2 ⌋`,用了第一种方法。
看了题解后发现还有一个限制条件，多数的个数大于`nums.length/2`,用sort方法两行就完事了，但是耗时挺长的

### 代码

-------
**方法一**
声明一个数组，下标对应`nums`中的元素，值对应元素出现的次数，最后输出数组中最大值的下标
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let arr = [0]
    let num = 0
    for (i = 0; i < nums.length; i++) {
        arr[nums[i]] = (arr[nums[i]]) ? arr[nums[i]] + 1 : 1
        if (arr[nums[i]] > arr[num]) {
            num = nums[i]
        }
    }
    return num
};
```
----

**方法二**
因为多数的个数大于`nums.length/2`，所以排序后中间位置`nums[Math.floor(nums.length/2)]`必然是多数

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    nums.sort(function (a, b) { return a - b; })
    return nums[Math.floor(nums.length/2)]
};
```


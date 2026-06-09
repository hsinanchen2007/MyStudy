### 解题思路
因为 js 中没有红黑树这样的数据结构，要求满足时间复杂度的暂时只想到用 三个变量 分别保存 第一大，第二大和第三大 的数

PS： 如果不考虑时间复杂度，可以用暴力破解法，滑动窗口法，通过 js 手写实现一个最小堆数据结构法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {
    let one = nums[0]
    let two = -Infinity
    let three = -Infinity
    for (let i = 0; i < nums.length; i++) {
        let index = nums[i]
        if (index > one) {
            three = two
            two = one
            one = index
        } else if (index > two && index != one) {
            three = two
            two = index
        } else if (index > three && index != two && index != one) {
            three = index
        }
    }
    return nums.length >= 3 && three != -Infinity ? three : one
};
```
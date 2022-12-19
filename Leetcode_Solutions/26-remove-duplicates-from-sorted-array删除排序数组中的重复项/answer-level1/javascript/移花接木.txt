### 解题思路
一、需要返回长度n
因为：返回数组的长度n=原数组的长度-重复数
所以：遍历nums[i] === nums[i-1]就是重复数字

二、原数组改变前n个数排序显示
因为：产生两个相同的数nums[i]，nums[i-1]会触发nums[i+1]向前位移到nums[i-u]
所以：nums[i-u] = nums[i]

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var u = 0
    for (var i = 1; i < nums.length; i ++) {
        if (nums[i] === nums[i-1]) {
            ++u
        } else {
            nums[i-u] = nums[i]
        }
    }
    return nums.length - u
};
```
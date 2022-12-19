### 解题思路
此处撰写解题思路
splice截取到指定位置，再将返回值添加到nums
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    let newnums = nums.splice(nums.length - k)
    nums.unshift(...newnums)
};
```
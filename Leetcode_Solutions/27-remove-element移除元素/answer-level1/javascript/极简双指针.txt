### 解题思路

![image.png](https://pic.leetcode-cn.com/4f3aa1155b80214c4393d5fcc526d0143ad0357fe37851bba069d256ccf0fc5e-image.png)

双指针逐个替换
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    if (!nums.length) return 0;
    let ind = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[ind] = nums[i];
            ind++;
        }
    }
    return ind;
};
```
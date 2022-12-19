```javascript []
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === val) {
           nums.splice(i,1)
        }
    }
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === val) {
           nums.splice(i,1)
        }
    }
    return nums.length
};
```
![WX20190917-151225.png](https://pic.leetcode-cn.com/6d362423704cfb83f6f71420856aeffd03574592cebb4663a8ad7dfd2711749d-WX20190917-151225.png)


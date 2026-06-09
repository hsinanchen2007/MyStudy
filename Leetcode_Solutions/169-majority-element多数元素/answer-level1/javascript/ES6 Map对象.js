### 解题思路
不一定非要排序，试一试用ES6的map对象

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var nmap = new Map, len = nums.length
    for (let i = 0; i < len; i++) {
        nmap.has(nums[i]) ? nmap.set(nums[i], nmap.get(nums[i]) + 1) : nmap.set(nums[i], 1)
        if (nmap.get(nums[i]) >= len / 2) { return nums[i] }
    }
};
```
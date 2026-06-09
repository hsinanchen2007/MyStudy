### 解题思路
![image.png](https://pic.leetcode-cn.com/e576a88058f23e8c1f1badec6be00079bc76cc9810861516100b6dfb5d679195-image.png)

dp递归
注意如果是0的话，+0,-0都可以，所以是两种
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} S
 * @return {number}
 */
var findTargetSumWays = function (nums, S) {
    if (nums.length === 1) {
        if (Math.abs(nums[0]) === Math.abs(S)) {
            if (S === 0) {
                return 2;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return findTargetSumWays(nums.slice(1), S - nums[0]) + findTargetSumWays(nums.slice(1), S + nums[0]);
    }
};
```
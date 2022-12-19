### 解题思路
见注释
![image.png](https://pic.leetcode-cn.com/f358ce2c0587b6de5f8efb5ea6c3fbc0201b2fd15504001e72ecc160043fa391-image.png)
### 代码


```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
// 动态规划，递归求解，超出时间限制，，，，蛋疼
// 思路很简单，偷了第一户，那就只能得到第一户与剩下的n - 2户中偷的的最大值, 即nums[1] + rob(nums.slice(2))
// 不偷第一户，那最大值，就是n - 1 户中偷的的最大值， 即rob(nums.slice(1)
// 那动态方程就是：Math.max(nums[0] + rob(nums.slice(2)), rob(nums.slice(1)));
// 可惜啊： 超出时间限制，因为前面很多结果没保留，后面没用上；
var rob_recursive = function(nums) {
    const length = nums.length; 
    if(length < 2) {
        return length && nums[0];
    }

    if (length === 2) {
        return Math.max(nums[0], nums[1]);
    }

    if (length === 3) {
        return Math.max(nums[1], nums[0] + nums[2]);
    }

    return Math.max(nums[0] + rob(nums.slice(2)), rob(nums.slice(1)));
};

// 动态规划，遍历求解
// 规划思路和上面一样：res[i] = Math.max(nums[i] + res[i - 2], res[i - 1]);
// 只不过这一次是反着来:
// 空间复杂度还可以优化
var rob = function(nums) {
    const length = nums.length; 
    if(length === 0) {
        return 0;
    }
    let res = [];
    for(let i = 0; i < length; i++) {
        res[i] = Math.max(nums[i] + (res[i - 2] || 0), (res[i - 1] || 0));
    }
    return res[length - 1];
}
```
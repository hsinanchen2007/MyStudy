### 解题思路
![image.png](https://pic.leetcode-cn.com/4b75f2234d57cd520c1a8d0e6549e65080e39129664330ce4e6758caa9538ef9-image.png)

先跟着本能和直觉用了第一个递归，能work但是TLE了。于是用动态规划数组，这下快了，直接AC了。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function (nums) {
    // works but too slow, TLE
    if (false) {
        if (nums.length === 0) return 0;
        else if (nums.length === 1) return nums[0];
        else if (nums.length === 2) return Math.max(nums[0], nums[1]);
        else {
            let lastIdx = nums.length - 1,
                secondPrevArr = nums.slice(0, lastIdx - 1),
                prevArr = nums.slice(0, lastIdx);

            return Math.max(massage(secondPrevArr) + nums[lastIdx], massage(prevArr));
        }
    }

    // better dynamic planning, better performance
    if (nums.length === 0) return 0;
    
    let dp = new Array(nums.length);

    nums.forEach((val, idx, arr) => {
        if (idx === 0) dp[0] = val;
        else if (idx === 1) dp[1] = val > arr[0] ? val : arr[0];
        else {
            dp[idx] = Math.max(dp[idx - 2] + val, dp[idx - 1]);
        }
    });

    return dp.pop();
};
```
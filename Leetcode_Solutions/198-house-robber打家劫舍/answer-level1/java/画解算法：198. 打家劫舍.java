
### 思路

- 标签：动态规划
- 动态规划方程：`dp[n] = MAX( dp[n-1], dp[n-2] + num )`
- 由于不可以在相邻的房屋闯入，所以在当前位置 `n` 房屋可盗窃的最大值，要么就是 `n-1` 房屋可盗窃的最大值，要么就是 `n-2` 房屋可盗窃的最大值加上当前房屋的值，二者之间取最大值
- 举例来说：1 号房间可盗窃最大值为 $3$ 即为 `dp[1]=3`，2 号房间可盗窃最大值为 $4$ 即为 `dp[2]=4`，3 号房间自身的值为 $2$  即为 `num=2`，那么 `dp[3] = MAX( dp[2], dp[1] + num ) = MAX(4, 3+2) = 5`，3 号房间可盗窃最大值为 $5$
- 时间复杂度：$O(n)$，$n$ 为数组长度

### 代码

```Java []
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        int[] dp = new int[len + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= len; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[len];
    }
}
```
```JavaScript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const len = nums.length;
    if(len == 0)
        return 0;
    const dp = new Array(len + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(let i = 2; i <= len; i++) {
        dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    return dp[len];
};
```


### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/754ce70c237c1886f9f10f3448887e0fedd4ef0e610ab3254cfa4417a0698f6b-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/6e00686f5c76de6709037da7c0e3cc702d4ba256a66d795d466c107956eaeb4e-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/2919d7f42c7b73f42102a4604aed2f74bc4576ecb985872f3e296354b408c94b-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/9c79d79b2ccdfe6055c3889de1fd3c522fd0805c210102378cf9d97f300627f3-frame_00004.png),![frame_00005.png](https://pic.leetcode-cn.com/9fd0c4dbb0b17971a9277407053ac67fdf231d745042993f9cc746f3333ff713-frame_00005.png)>


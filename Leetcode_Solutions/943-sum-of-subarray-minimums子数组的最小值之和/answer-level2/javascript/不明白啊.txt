
并不会做这道题，看了别人的解题报告写的，写完了也没有很明白，权当做个记录。

dp的做法重点在于找到递推关系，就是如何根据已有的dp数据计算出当前dp[i][j]的值
dp[i][j]=x表示用前j个数，分割成i组，各种分组求和中最大值里面的最小值

考虑对于求dp[4][8]的值，分组方法可以有好几种，比如dp[3][7]和nums[8],意思是前7个数分成3个，第八个数单独分成一组；
也可以是dp[3][6] + (nums[7] + nums[8])，意思是前6个数分3组，第7，8，两个数字作为一组，这样也就把8个数字分成了4组。以此类推，最低可以到dp[3,3] + (nums[4,5,6,7,8])

没明白是怎么样的思路想到的这种方法，以及为什么这样保证了结果的正确性
```
/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
var splitArray = function(nums, m) {
    let dp = []
    for(let i = 0; i < nums.length; i++) {
        dp[i] = []
        dp[0][i] = i == 0 ? nums[i] : nums[i] + dp[0][i-1] 
    }
    for(let i = 1; i < nums.length; i++) {
        for(let j = nums.length - 1; j >= i; j--) {
            let s = 0
            for(let k = j; k>=i; k--) {
                s += nums[k]
                let min = Math.max(dp[i-1][k-1], s)
                dp[i][j] = dp[i][j] ? Math.min(dp[i][j], min): min 
             }
        }
    }
    return dp[m-1][nums.length-1]
};
```
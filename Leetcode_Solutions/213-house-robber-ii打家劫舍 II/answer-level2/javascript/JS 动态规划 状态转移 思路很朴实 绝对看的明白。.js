### 解题思路
这道题增加了一个条件，房子是环形的，其实这个条件只影响最后一个房子偷不偷，当0号房子偷了，最后一个房子就不能偷，当0号房子没偷，则最后一个房子可以偷。

所以我们可以用一个二维数组保存当前状态。
`dp[i][0]` 表示小偷走到第i, 没有偷第一个房子的最大值  
`dp[i][1]` 表示小偷走到i, 偷了第一个房子的最大值。

那么状态转移方程怎么确定呢？
对于第i个房子，如果前一个房子我偷了就不能偷这个房子，所以我走到第i个房子，能够获得的最大值为前一个房子能够获得的最大值。
    此时 `dp[i] = dp[i-1]`;
对于前一个房子我没有偷，那么我就可以偷这个房子，所以我走到第i个房子，能够获得的最大值为前两个房子能够获得的最大值 + 当前房子的价值。
    此时 `dp[i] = dp[i-2] + nums[i]`
状态转移方程就确定了。

特殊情况处理？
当i是最后一个房间的时候
```javascript
    dp[i-1][0] = Math.max(dp[i-1][0], dp[i-2][0] + nums[i]);
    //如果第一个房间没有被偷，那么最后一个房间就是个正常的房间。
    dp[i-1][1] = dp[i-1];
    //如果第一个房间被偷了，那么最后一个房间就不能偷了，此时我们只有一个选择，就是不偷，只能等于dp[i-1];
```

剩下的就是边界状态了。

dp[0][0] = 0; 走到第0房子的时候，不偷，那不就是只有0；
dp[0][1] = nums[0]; 走到第0房子的时候，偷了，那不就是收获了nums[0] ;
dp[1][0] = nums[1]; 走到第1房子的时候，如果第零个房子我没有偷，那我就可以偷第一个房子，一共收获了nums[1] ;
dp[1][1] = nums[0]; 走到第1房子的时候，如果第零个房子我偷了，那我就不能偷第1个房子，一共收获了nums[0] ;

然后就可以写代码了！看下面。
其实这个代码 时间复杂夫O(n)已经超越 90+%了，空间O(n),内存消耗就已经超越100%，

然后我们还可以再次优化空间，我们观察状态转移方程，发现，其实只用了
 `dp[i-1][0]`
 `dp[i-1][1]`
 `dp[i-2][0]`
 `dp[i-2][1]`
四个状态，所以我们可以用四个基本数据类型保存这四个状态，空间复杂度优化为O(1);
注意每次循环要用 `temp` 保存`dp[i-1]`，因为当前的`dp[i-1]`,在下一次就是`dp[i-2]`了。
代码在最下面。
### 代码
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(nums.length <= 1){
        return nums[0] ? nums[0] : 0;
    }
    let dp = [];
    //dp[i][0,1]
    //i表示房间号，[0,1]表示有没有投过0号房间;
    for(let i = 0; i < nums.length; i++){
        dp[i] = [];
    }
    dp[0][1] = nums[0];
    dp[0][0] = 0;
    dp[1][1] = nums[0];
    dp[1][0] = nums[1];
    let max = Math.max(dp[1][0], dp[1][1]);
    for(let i = 2; i < nums.length; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
        if(i < nums.length -1){
            dp[i][0] = Math.max(dp[i-1][0], dp[i-2][0] + nums[i]);
            dp[i][1] = Math.max(dp[i-1][1], dp[i-2][1] + nums[i]);
        }else{
            dp[i][0] = Math.max(dp[i-1][0], dp[i-2][0] + nums[i]);
            //如果第一个房间没有被偷，那么最后一个房间就是个正常的房间。
            dp[i][1] = dp[i-1];
            //如果第一个房间被偷了，那么最后一个房间就不能偷了，此时我们只有一个选择，就是不偷，只能等于dp[i-1];
        }
        max = Math.max(max, Math.max(dp[i][0], dp[i][1]));
    }
    return max;
};
```
优化空间之后。
```javascript
var rob = function(nums) {
    if(nums.length <= 1){
        return nums[0] ? nums[0] : 0;
    }

    let dp_2_1 = nums[0]
    let dp_2_0 = 0; 
    let dp_1_1 = nums[0];
    let dp_1_0 = nums[1];
    let max = Math.max(dp_1_1, dp_1_0);
    for(let i = 2; i < nums.length; i++){
        if(i < nums.length -1){
            let temp0 = dp_1_0;
            let temp1 = dp_1_1;
            dp_1_0 = Math.max(dp_1_0, dp_2_0 + nums[i]);
            dp_1_1 = Math.max(dp_1_1, dp_2_1 + nums[i]);
            dp_2_0 = temp0;
            dp_2_1= temp1;
        }else{
            dp_1_0 = Math.max(dp_1_0, dp_2_0 + nums[i]);
            dp_1_1 = dp_1_1;
            //因为最后一个房间如果要偷的话，只能找没有偷过0房间的。
            //如果最后一个房间，不偷的话，就可以找前一个被偷了的不管第0房间有没有被投过，
        }
        max = Math.max(max, Math.max(dp_1_0, dp_1_1));
    }
    return max;
};
```
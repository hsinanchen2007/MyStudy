### 解题思路
没有遇到过动态规划的问题
还是一边百度一边做的 加了点注释
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if (nums.length == 1) {
        return nums[0]
    }
    if (nums.length == 0) {
        return 0
    }
    let dp0=0;//今天没有接受  第一天
    let dp1=nums[0]//今天接受 第一天
    for(let i=1;i<nums.length;i++){//从i=1 开始 也就是第二天
        let recive=dp0+nums[i],//今天接受 第二天
            norecive=Math.max(dp0,dp1);//今天不接受 比较下前两天运算结果
        // console.log(dp0,dp1)
        dp0=norecive;//不去接受
        dp1=recive;//接受
        
    }

    return Math.max(dp0,dp1)
};
```
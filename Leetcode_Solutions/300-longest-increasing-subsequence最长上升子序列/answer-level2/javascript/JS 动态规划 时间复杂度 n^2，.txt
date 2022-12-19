### 解题思路
 1. 找状态
    dp[i]为最大上升子序列 满足两个条件
        1. nums[i] > nums[j]
        2. j 为所有小于 i，且在i前面的元素中，dp[j]最大的。
2. 转移方程
```
    0<= j < i
    if(nums[j] < nums[i]){
            max = Math.max(dp[j],max);
    }
    dp[i] =max + 1
```
3. 初始状态，边界
```
    dp[0] = [1]; 
```
4. 顺序
    从小到大
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    if(nums.length <= 1){
        return nums.length;
    }
    let n = nums.length;
    let maxLength = 0;
    let dp = [];
    dp[0] = 1;
    for(let i = 1;i<n;i++){
        let max = 0;
        for(let j = i-1; j >= 0 ;j--){
            if(nums[j] < nums[i]){
                 max = Math.max(dp[j],max);
            }
        }  
        dp[i] = max + 1;
        maxLength = Math.max(maxLength, dp[i]);
    }
    return maxLength;
};
```
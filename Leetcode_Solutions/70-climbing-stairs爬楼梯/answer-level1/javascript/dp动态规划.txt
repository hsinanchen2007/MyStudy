### 解题思路
动态规划问题
无论怎么走
最后一步只有 1 和 2
假设dp[n]为总的可能
那么 最后一步可能就为
dp[n]=dp[n-1]+dp[n-2] 

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n==1){
        return 1
    }
    if(n==2){
        return 2
    }
let dp=[];
dp[0]=1;
dp[1]=2;
for(let i=2;i<n;i++){
    dp[i]=dp[i-1]+dp[i-2]
}
return dp[n-1]
};
```
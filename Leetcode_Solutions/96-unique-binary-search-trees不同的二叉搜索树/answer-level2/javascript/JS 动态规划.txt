### 解题思路】
 子树得个数与子树内容无关，只与子树包含的元素个数有关 
    数组长为i, 0 < j < i 
     则  
*   sum[j] = dp[j-1] * dp[i-j]  (左边子树有dp[i-1]个状态，右边子树有dp[n-i]个状态，所以以 i 为根，一共有 乘积个状态)
 又有 
*   dp[n] = 所有小于 n 得点作为根节点，所能构造得二叉搜索树之和，
 所以
*   dp[i] = sum[0]+sum[1]+sum[2]+sum[3]+...sum[i]

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    let dp = [];
    dp[0] = 1;
    dp[1] = 1;
    for(let i = 2; i <= n; i++){
        dp[i] = 0;
        for(let j = 1; j <= i; j++){
            dp[i] += dp[j-1] * dp[i-j]; 
        }
        
    }  
    return dp[n]
};

```
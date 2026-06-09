【注意】题目中m,n均大于1

【递归】时间复杂度O(n²)，空间复杂度O(1)

```swift
var map = new Map();
var cuttingRope = function(n) {
    if(n == 2 || n==1) return 1;
    if(map.has(n)) return map.get(n);
    let max = 0;
    for(let i=1;i<n;i++) max = Math.max(max, Math.max(i*(n-i) , cuttingRope(n-i)*i));
    map.set(n, max);
    return max;
};
```
【动态规划】 时间复杂度O(n²) 空间复杂度 O(n)

`状态` : 要切分绳子的长度n

`dp[n]` : 该长度n的绳子切分m段后各段长度的乘积

`出口条件`： dp[2] = 1

`状态转移方程`： `dp[n] = max(max( dp[n-len])*len, (n-len)*len ); `

(其中，len满足 `0<len<n`)  (因 `dp[n-len])*len` 中不包含切成` n-len` 和 `len` 两段的情况， 所以要将 `(n-len)*len` 加入比较)

```javascript
var cuttingRope = function(n) {
    let dp = new Array(n+1).fill(0);
    dp[2] = 1;
    for(let i=3;i<=n;i++)
        for(let j=1;j<i;j++) 
            dp[i] = Math.max(dp[i], Math.max(dp[i-j]*j, (i-j)*j));
    return dp[n];
};
```
相似的题目如 [`换零钱`](https://leetcode-cn.com/problems/coin-change/)。
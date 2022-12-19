```
/**
 * @param {number} K
 * @param {number} N
 * @return {number}
 */
let dp = undefined
var superEggDrop = function(K, N) {
    dp = new Array(K + 1)
    for(let i = 0 ;i <= K; i++) dp[i] = new Array(N + 1).fill(-1)
    return dpf(K, N)
};

// 剩余k个鸡蛋、n层楼需要遍历
function dpf(k, n) {
    if(dp[k][n]!== -1) return dp[k][n]
    if(n === 0) return 0
    if(k === 1) return n
    let ans = Infinity
    let left = 1
    let right = n
    /*
    注意， 这里的二分法不是二分法抛鸡蛋，每次抛鸡蛋实际还是暴力循环遍历。
    这里能用二分法，是因为dpf（k - 1, i - 1）和dpf(k, n - i)一个单调递增， 一个单调递减
    最大最小问题其实就是要找两者相交的那个点， 所以可以用二分法
    */
    while(left <= right) {
        const mid = Math.floor((left + right) / 2)
        const broken = dpf(k - 1, mid - 1)
        const not_broken = dpf(k, n - mid)
        if(broken > not_broken) {
            right = mid - 1
            ans = Math.min(ans, broken + 1)
        } else if(broken < not_broken){
            left = mid + 1
            ans = Math.min(ans, not_broken + 1)
        } else {
            ans = Math.min(ans, broken + 1)
            break
        }
    }
    dp[k][n] = ans
    return ans
}
```

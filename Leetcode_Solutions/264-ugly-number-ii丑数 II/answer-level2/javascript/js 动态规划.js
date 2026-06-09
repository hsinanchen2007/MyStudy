### 解题思路
    /**
    三指针法
    因为每个数字都要被计算三次，一次是乘以二，一次是乘以三，一次是乘以5
    所以定义三个指针，p_2, p_3, p_5,
    这三个指针的起点是一样的，都是0，
    如果当前的数字是乘以3得到的，就将p_3向前移动，
    如果当前的是乘以2得到的，就将p_2向前移动，
    如果当前的是乘以5得到的，就将p_5向前移动
     */

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let dp = [1];
    let p_2 = 0;
    let p_3 = 0;
    let p_5 = 0;
    while(dp.length < n){
        let now = Math.min(Math.min(dp[p_2] * 2, dp[p_3] * 3), dp[p_5] * 5);
        if(now == dp[p_2] * 2){
            p_2++;
        }
        if(now == dp[p_3] * 3){
            p_3++;
        }
        if(now == dp[p_5] * 5){
            p_5++;
        }
        dp.push(now);
    }
    return dp[n-1];
};
```
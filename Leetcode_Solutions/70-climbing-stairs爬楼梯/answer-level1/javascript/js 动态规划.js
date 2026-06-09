```
/**
 * @param {number} n
 * @return {number}
 * 动态规划  num(n) = num(n - 1) + num(n - 2)
 * 加一个hash表，记录一下已经计算过的值，避免重复计算，不然会潮湿
 */
var climbStairs = function(n) {
    let isCaled = {
        1: 1,
        2: 2
    };
    const calPlans = function(n) {
        if (isCaled[n])
            return isCaled[n];
        let first = calPlans(n - 1);
        isCaled[n - 1] = first;
        let second = calPlans(n - 2);
        isCaled[n - 2] = second;
        return first + second;
    }
    return calPlans(n);
};
```
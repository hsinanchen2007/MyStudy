1.动态规划
很容易想到，如果第一个人正好坐在自己的位置，那么之后所有的人都会坐在自己的位置。
如果第一个人正好坐在第n个人的位置，那么第n个人没可能坐在自己的位置。
如果第一个人坐在除了自己位置以及第n个人的位置之外的任何位置，情况就如同n-1个座位情况。
所以转移方程为: **dp[i] = 1 / i + (i - 2) / i * dp[i - 1]**
```
var nthPersonGetsNthSeat = function(n) {
    let dp = [0, 1];
    for(let i = 2;i <= n;i++) {
        dp[i] = (1 / i) + (dp[i - 1] * (i - 2) / i);
    }
    return dp[n];
};
```
2.数学法
上式通过数学归纳法发现
当n = 1时，概率为1,
其他情况，概率为0.5。
```
var nthPersonGetsNthSeat = function(n) {
    if(n == 1) {
        return 1;
    }
    return 0.5;
};
```



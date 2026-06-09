暴力递归
```
var fib = function(N) {
    if(N==0)return 0;
    if(N==1)return 1;
    return fib(N-1)+fib(N-2);
};
```
动态规划：数组存放所有值，返回最后一个即可
```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
    var dp=[0,1,1];
    for(var i=3;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[N];
};
```
动态规划优化：优化上述方法：只需要存放前两个值即可，减小空间消耗
```
var fib = function(N) {
    if(N==0)return 0;
    if(N==2||N==1)return 1;
    var prev=1,curr=1;
    for(var i=3;i<=N;i++){
        var sum=prev+curr;
        prev=curr;
        curr=sum;
    }
    return curr;
};
```

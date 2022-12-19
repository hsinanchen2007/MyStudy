### 解题思路
此题为动态规划入门题
当台阶为1阶时候，走法为1种
当台阶为2阶时候，走法为2种
当台阶为3阶时候，走法为f(1)+f(2)=3种
因此我最初的做法是递归，也称暴力法
```
var climbStairs = function(n) {
    if(n<0) return 0
    if(n===1) return 1
    if(n===2) return 2
    var a=1,b=2,sum=0;
    return climbStairs(n-1)+climbStairs(n-2)
};`
```
当n=45时，就超出了时间限制，因为此解法的时间复杂度为O(2^n)
因而定义了一个中间变量sum,该变量为当前楼梯阶层的最优结果
### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n<0) return 0
    if(n===1) return 1
    if(n===2) return 2
    var a=1,b=2,sum=0;
    for(var i=3;i<=n;i++){
        sum = a+b;
        a=b
        b=sum
    }
    return sum
};
```
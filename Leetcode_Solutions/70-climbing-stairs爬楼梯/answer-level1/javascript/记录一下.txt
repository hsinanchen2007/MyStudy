```
/**
 * @param {number} n
 * @return {number}
 */

// 递归
var climbStairs = function(n) {
    if(n==1) return 1
    if(n==2) return 2
    return climbStairs(n-1)+climbStairs(n-2)
};

// 尾递归
var climbStairs = function(n,a=1,b=2) {
    if(n==1) return a
    if(n==2) return b
    return climbStairs(--n,b,a+b)
};

// 循环
var climbStairs = function(n) {
    let arr = [1,2]
    if(n==1) return arr[0]
    if(n==2) return arr[1]
    for(let i = 2; i<n; i++)
        arr.push(arr[i-1]+arr[i-2])
    return arr.pop()
};

// 参考官方
var climbStairs = function(n) {
    const sqrt5=Math.sqrt(5)
    const fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1)
    return Math.round(fibn/sqrt5)
}

```

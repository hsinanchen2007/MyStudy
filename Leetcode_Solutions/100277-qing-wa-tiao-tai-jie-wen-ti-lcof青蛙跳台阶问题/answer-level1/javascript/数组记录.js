### 解题思路
当n>=3的时候可以用N（n-1）+N(n-2)公式

需要注意的是边界问题
一个台阶 N =1 一种跳法
两个台阶 N = 2 两种跳法
没有（0）台阶 N=0  一种跳法。  n = 0 answer = 1 ，正好 f[2] = f[1] + f[0]，就是一个完整的 fib 数列

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function(n) {
    const arr = new Array(n+1).fill(0);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(let i = 3; i<=n;i++){
        arr[i] = (arr[i-1] + arr[i-2])%1000000007
    }
    return arr[n]
};
```
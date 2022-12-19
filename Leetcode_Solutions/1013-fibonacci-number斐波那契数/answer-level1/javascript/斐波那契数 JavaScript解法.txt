### 解题思路
解法1是最简单的解法但也是最耗时的解法。

解法2从i=2开始迭代N，将第i个元素设置前两个元素的和，这样最后一个元素的值就是斐波那契数。

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */

// 解法1
var fib = function(N) {
    if (N < 2) return N;
    return fib(N - 1) + fib(N - 2);
}


// 解法2
var fib = function(N) {
    if ( N <= 1) return N;
    const result = new Array(N);
    result[0] = 0;
    result[1] = 1;
    for (let i = 2; i < N + 1; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
    return result[N];
};
```
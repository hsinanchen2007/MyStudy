### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
    if(N <= 1) return N
    const store = new Array(N).fill(0).map((val,idx) => idx)
    for(let i = 2; i <= N; i ++) store[i] = store[i - 1] + store[i - 2]
    return store[N]
};
```
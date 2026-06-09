### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let arr = new Array(n+1).fill(null);
    arr[0] = 0;
    arr[1] = 1;
    for(let i=2; i <= n; i++){
        arr[i] = arr[i-1]%1000000007 + arr[i-2]%1000000007
    }
    return arr[n]%1000000007
};
```
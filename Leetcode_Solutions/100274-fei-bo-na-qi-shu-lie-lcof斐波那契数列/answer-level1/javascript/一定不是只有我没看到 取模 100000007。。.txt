### 解题思路

别忘记取模啊

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if(n === 0) return 0
    if(n === 1) return 1
    let res1 = 0
    let res2 = 1
    for(let i = 1;i<n;i++){
        let t = res1
        res1 = res2
        res2 = (t + res2) % 1000000007
    }
    return res2
};
```
### 解题思路
解题思路：fn = f0 + f1，然后要注意题目要进行取模

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let i = 1,f0 = 0, f1 = 1,fn = 0
    fn = !n ? 0 : f0 + f1
    while(n > i) {
        fn = (f0 + f1) > 1000000007 ? (f0 + f1) % 1000000007 : (f0 + f1)
        f0 = f1
        f1 = fn
        i++
    }
    return fn
};
```
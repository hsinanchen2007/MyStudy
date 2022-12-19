### 解题思路
...

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let limit = Math.pow(10, n)
    let cur = 1
    let ans = []
    while(cur < limit) {
        ans.push(cur)
        cur++
    }
    return ans
};
```
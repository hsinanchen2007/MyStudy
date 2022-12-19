### 解题思路
循环解法(非递归&非dp)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function (n) {
    if (n === 0) return 1
    if (n === 1) return 1
    let left = 1, right = 1, count = 2, now = 0;
    while (count <= n) {
        now = left % 1000000007 + right % 1000000007;
        left = right;
        right = now;
        count++;
    }
    return now % 1000000007
};
```
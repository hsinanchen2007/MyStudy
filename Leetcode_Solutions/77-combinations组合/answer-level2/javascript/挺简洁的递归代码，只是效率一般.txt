### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
function recusion(start, result, n, k, results) {
    if (result.length === k) {
        results.push(result);
        return;
    }
    for (let i = start; i <= n; i++) {
        recusion(i + 1, [...result, i], n, k, results);
    }
}
var combine = function (n, k) {
    let results = [];
    recusion(1, [], n, k, results);
    return results;
};
```
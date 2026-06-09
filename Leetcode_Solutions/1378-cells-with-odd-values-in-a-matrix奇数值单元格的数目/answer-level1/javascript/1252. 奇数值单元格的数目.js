### 解题思路
计算每行/每列增量操作次数 -> 输出 奇数行 * 偶数列 + 偶数行 \* 技术列

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function(n, m, indices) {
    let row = new Array(n).fill(0), col = new Array(m).fill(0)
    indices.forEach(([r, c]) => {
        row[r]++
        col[c]++
    })
    let odd_row = row.filter(val => { return val%2 === 1}).length
    let odd_col = col.filter(val => { return val%2 === 1}).length
    return odd_row * (m - odd_col) + odd_col * (n - odd_row)
};
```
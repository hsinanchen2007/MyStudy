### 解题思路
.当前行 curRow 为 0 或 n-1 时，箭头发生反向转折。
方法一： 从左到右按箭头方向迭代 s ，将每个字符添加到合适的行。之后从上到下遍历行即可。

我们假定 n=numRows :

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows == 1) return s;
    const len = Math.min(s.length, numRows);
    const rows = [];
    for(let i = 0; i < len; i++) rows[i] = "";
    let loc = 0;
    let down = false;

    for(const c of s) {
        rows[loc] += c;
        if(loc == 0 || loc == numRows - 1)
            down = !down;
        loc += down ? 1 : -1;
    }

    let ans = "";
    for(const row of rows) {
        ans += row;
    }
    return ans;
};
```
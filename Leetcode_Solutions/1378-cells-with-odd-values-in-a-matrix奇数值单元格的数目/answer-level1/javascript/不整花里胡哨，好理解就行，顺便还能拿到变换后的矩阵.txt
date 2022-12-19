### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function (n, m, indices) {
    let arr = new Array(n).fill(new Array(m).fill(0));
    let count = 0;
    for (let i = 0; i < indices.length; i++) {
        let x = indices[i][0];
        let y = indices[i][1];
        arr = arr.map((item, index) => {
            return item.map((ii, iix) => {
                if (index === x) {
                    ii++;
                }
                if (iix === y) {
                    ii++;
                }
                if (i === indices.length - 1) {
                    ii % 2 !== 0 && count++;
                }
                return ii;
            })
        })
    }
    return count;
};
```
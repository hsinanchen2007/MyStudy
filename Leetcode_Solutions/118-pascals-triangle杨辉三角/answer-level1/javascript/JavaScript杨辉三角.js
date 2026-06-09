### 解题思路
看了大神的解题思路：如果不是该列数组的首位或者最后一位，则值为a[i-1][j-1] + a[i-1][j] ，否则值为1

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 * 思路是判断如果不是该列数组的首位或者最后一位，则值为a[i-1][j-1] + a[i-1][j] ，否则值为1
 */


var generate = function (numRows) {
    const result = [];
    if (numRows <= 0) {
        return result;
    }
    let i = 0, j = 0;
    for (let i = 0; i < numRows; i ++) {
        const subArr = [];
        for (let j = 0; j <= i; j++) {
            if (j > 0 && j < i) {
                subArr.push(result[i-1][j-1] + result[i-1][j]);
            } else {
                subArr.push(1);
            }
        }
        result.push(subArr);
    }
    return result;
};
```
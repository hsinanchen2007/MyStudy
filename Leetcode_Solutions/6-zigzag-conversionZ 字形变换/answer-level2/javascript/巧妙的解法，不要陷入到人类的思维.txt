### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
// 按照行，遍历字符串时，从上到下遍历，当碰到边界条件的时候，改变遍历方向，直接得到每一行的数据
var convert = function(s, numRows) {
    if (s.length < 3 || numRows < 2) return s
    let row = 0
    const arr = []
    let reverseFlag = false // 转向flag
    for(const i of s) {
        if (!arr[row]) arr[row] = ''
        arr[row] += i
        if (row === numRows - 1) {
            reverseFlag = true
        } else if (row === 0) {
            reverseFlag = false
        }
        if (reverseFlag) {
            row--
        } else {
            row++
        }
    }
    return arr.join('')
};


```
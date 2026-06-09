### 解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const len = arr.length
    if (len === 0 || k === 0) {
        return []
    }
    arr.sort((a, b) => a - b)
    const res = arr.splice(0, k)
    return res
};
```
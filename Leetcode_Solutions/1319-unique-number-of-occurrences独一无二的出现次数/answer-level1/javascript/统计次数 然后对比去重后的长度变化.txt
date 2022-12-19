### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    let keys = {}
    arr.forEach(a => {
        let v = keys[a]
        if(v) {
            keys[a] = v + 1
        } else {
            keys[a] = 1
        }
    })
    let values = Object.values(keys)
    let valuesLen = values.length
    let removeRepeatLen = [...new Set(values)].length
    return valuesLen === removeRepeatLen
};
```
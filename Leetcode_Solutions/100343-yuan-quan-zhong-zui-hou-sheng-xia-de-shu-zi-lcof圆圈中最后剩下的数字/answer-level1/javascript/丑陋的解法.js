### 解题思路


### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    let len = n, index = 0
    let arr = []
    for (let i = 0; i < n; i++) {
        arr.push(i)
    }
    while(len > 1) {
        // 当数组的长度大于当前要删除的序号时
        if (len >= m + index) {
            arr.splice(index + m - 1, 1)
            index += m - 1
        } else {
            // 如果数组的长度小于当前要删除的序号，取当前要删除的序号减去上次删除时数组剩余的长度 m - (len - index)
            let sort = (index + m - len) % len === 0 ? len : (index + m - len) % len
            arr.splice(sort - 1, 1)
            index = sort - 1
        }
        len = arr.length
    }
    return arr[0]
};
```
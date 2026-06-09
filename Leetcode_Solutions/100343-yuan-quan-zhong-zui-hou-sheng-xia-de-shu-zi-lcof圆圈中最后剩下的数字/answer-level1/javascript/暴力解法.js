### 解题思路
暴力解法

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    let arr = Array(n).fill(0).map((e, i) => i)
    let lastCut = 0
    while(arr.length > 1){
        let cut = (m % arr.length + lastCut) % arr.length
        lastCut = cut > 0 ? cut - 1 : arr.length - 1
        cut, arr, arr.splice(lastCut, 1)
    }
    return arr[0]
};
```
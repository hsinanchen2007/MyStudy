### 解题思路
从小到大排序，从小到大取就可以。。。
### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var maxNumberOfApples = function(arr) {
    const len = arr.length
    arr.sort((a, b) => a - b)
    let count = 0
    let sum = 0
    for (let i = 0; i < len; i++) {
        sum += arr[i]
        if (sum <= 5000) {
            count ++
        } else {
            break
        }
    }
    return count
}; 
```
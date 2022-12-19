### 解题思路
- 从每一个 0 出发寻找更多的 0
- 首先判断 left 和 right 是不是 1， 如果不是继续判断是不是 undefined
- 将每个 0 出发找到的最大距离进行比较

### 代码

```javascript
/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
    let len = seats.length
    let max = 0
    for (let i = 0; i < len; i++) {
        if (seats[i] === 0) {
            let left = i -1
            let right = i + 1
            let count = 1
            while (seats[left] !== 1 && seats[right] !== 1) {
                   if (seats[left] === undefined && seats[right] === undefined) break
                   left--
                   right++
                   count++
            }
            max = Math.max(count, max)
        }
    }
    return max
    
};
```
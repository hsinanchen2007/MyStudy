### 解题思路
逆推，又target开始你推，如果出现负数或者，某些值小于1的情况，返回 false
### 代码

```javascript
/**
 * @param {number[]} target
 * @return {boolean}
 */
var isPossible = function(target) {
    if(target.length <= 1) return true
    target.sort((a, b) =>  b - a)
    let len = target.length
    let priority_queue = new queue(target)
    let sum = target.reduce((res, ele) => res + ele, 0)
    while(sum > len) {
        let max = priority_queue.data.shift()
        if(max <= sum - max) return false
        let diff = sum - max
        priority_queue.add(max - diff)
        sum = sum - diff
    }
    return sum === len
};
// 定义一个降序的队列
function queue(data) {
    this.data = data
}
queue.prototype.add = function(value) {
    for(let i = 0; i < this.data.length; i++) {
        if (value >= this.data[i]) {
            this.data.splice(i, 0, value)
            return
        }
    }
    this.data.push(value)
}
```
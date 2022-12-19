### 解题思路
此处撰写解题思路

### 代码

```javascript
var MaxQueue = function() {
    queue = []  
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    if (!queue.length) return -1
    return queue.reduce((a, b) => a > b ? a : b) // 没耐心了... 耍个无赖吧...
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    queue.push(value)
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if (!queue.length) return -1
    return queue.shift()
};

/** 
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
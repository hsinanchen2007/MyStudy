### 解题思路
此处撰写解题思路

### 代码

```javascript
var MaxQueue = function () {
    this.stack = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function () {
    if (this.stack.length === 0) return -1;
    return Math.max.apply(this, [...this.stack])
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function (value) {
    this.stack.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function () {
    if (this.stack.length === 0) return -1;
    return this.stack.shift();
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
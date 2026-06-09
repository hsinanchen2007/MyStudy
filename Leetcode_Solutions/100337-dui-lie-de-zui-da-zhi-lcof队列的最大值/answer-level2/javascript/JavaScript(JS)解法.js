### 解题思路
出队时要判断一下队列是否为空

### 代码

```javascript
var MaxQueue = function () {
    this.queue = [];
    this.maxValue = -1;
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function () {
    if (this.queue.length === 0) return -1
    return this.maxValue
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function (value) {
    this.queue.push(value);
    if (value > this.maxValue) {
        this.maxValue = value;
    }
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function () {
    if (this.queue.length === 0) return -1
    let val = this.queue.shift();
    if (this.queue.length === 0) {
        this.maxValue = -1;
    }
    if (val === this.maxValue) {
        this.maxValue = Math.max(...this.queue);
    }
    return val
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
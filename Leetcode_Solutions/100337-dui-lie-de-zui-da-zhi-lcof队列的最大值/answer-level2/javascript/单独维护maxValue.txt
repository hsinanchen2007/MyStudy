### 解题思路
![image.png](https://pic.leetcode-cn.com/d560ecb974e8822ed223805a48d9e7da865f6815ecd56df23eedb30737af41ae-image.png)

### 代码

```javascript
var MaxQueue = function() {
    this.queue = [];
    this.maxValue = -1;
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.maxValue;
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.queue.push(value);
    this.maxValue = Math.max(this.maxValue, value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if (!this.queue.length) {
        return -1;
    } else if (this.queue.length === 1) {
        this.maxValue = -1;
    } else if (this.queue[0]===this.maxValue) {
        let v = this.queue.shift();
         this.maxValue = Math.max(...this.queue);
         return v;
    }
    return this.queue.shift();
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
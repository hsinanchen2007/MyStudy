### 解题思路
虽然看不太懂题目，但实现一个队列只需一个栈即可，push入队，shift出队

### 代码

```javascript
var CQueue = function() {
    this.queue = []
    return null
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.queue.push(value)
    return null
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if(!this.queue.length) {
        return -1
    }
    return this.queue.shift()
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 * 解题思路：虽然看不太懂题目，但实现一个队列只需一个栈即可，push入队，shift出队
 */
```
### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function () {
    this.stackIn = []
    this.stackOut = []
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
    this.stackIn.push(x)
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function () {
    if (this.stackOut.length === 0) {
        while (this.stackIn.length) {
            this.stackOut.push(this.stackIn.pop())
        }
    }
    return this.stackOut.pop()
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function () {
    if (this.stackOut.length === 0) {
        while (this.stackIn.length) {
            this.stackOut.push(this.stackIn.pop())
        }
    }
    return this.stackOut[this.stackOut.length - 1]
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function () {
    return this.stackOut.length === 0 && this.stackIn.length === 0
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
```
### 解题思路
队列的特点为先进先出
栈的特点为先进后出

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.stack = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.stack.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const queue = []
    while (this.stack.length > 1) {
        queue.push(this.stack.shift())
    }
    const top = this.stack.shift()
    this.stack = queue
    return top
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    const queue = this.stack.slice()
    while (queue.length > 1) {
        queue.shift()
    }
    return queue.shift()
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.stack.length === 0
};

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```
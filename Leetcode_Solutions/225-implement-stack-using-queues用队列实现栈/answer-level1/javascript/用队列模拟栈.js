### 解题思路
此处撰写解题思路
因为 JavaScript 不支持队列，所以采用数组来模拟队列
在队列中，只支持 push(入队),shift(出队)
### 代码

```javascript
/**
 * Initialize your data structure here.
 * only push, shift allowed to use
 * only allowed to this read the queue[0]
 * you can read the queue.length
 */
var MyStack = function() {
     this.queue = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.queue.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    let newQueue = [];
    let result;
    while(this.queue.length - 1) {
        newQueue.push(this.queue.shift())
    }
    result = this.queue[0];
    this.queue = newQueue;
    return result;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    let result = this.pop();
    this.push(result);
    return result;  
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.queue.length;
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
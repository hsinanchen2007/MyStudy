方法跟 用栈模拟队列 差不多，关键在 pop 操作处理好就行

其中 top() 方法还是用了数组下标，我的理解是应该不允许用的，如果不用数组下标的话，应该会跟 pop 类似的处理，出队到剩下一个，然后获取 0 号元素，再回去。

```
/**
 * Initialize your data structure here.
 */
// 队列实现栈
// shift push
var MyStack = function() {
    this.queue = []
    this.helper = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.queue.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    while(this.queue.length > 1) {
        this.helper.push(this.queue.shift())
    }
    let a = this.queue.shift()
    while(this.helper.length) {
        this.queue.push(this.helper.shift())
    }
    return a
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.queue[this.queue.length-1]
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.queue.length === 0
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

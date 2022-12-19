主栈：记录数据，与pop操作

辅栈： push数据时，移动主栈中数据到辅栈，push后，再移回主栈

```
var CQueue = function() {
    this.stack = []
    this.helpStack = []
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    if (!this.stack.length) {
        this.stack.push(value)
    } else {
        while (this.stack.length) {
            this.helpStack.push(this.stack.pop())
        }
        this.stack.push(value)
        while (this.helpStack.length) {
            this.stack.push(this.helpStack.pop())
        }
    }
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    return this.stack.length ? this.stack.pop() : -1
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
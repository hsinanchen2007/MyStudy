按照题意,必须使用栈,一个栈 不可能,两个即可

```javascript
var MyQueue = function() {
    //输入栈
    this.istack = [];
    //输出栈
    this.ostack = [];
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    //将输出栈,转向输入栈
    while(this.ostack.length){
        this.istack.push(this.ostack.pop()); 
    }
    this.istack.push(x);
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    //将输出栈,转向输入站
    while(this.istack.length){
        this.ostack.push(this.istack.pop()); 
    }
    return this.ostack.pop();
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    while(this.istack.length){
        this.ostack.push(this.istack.pop()); 
    }
    return this.ostack[this.ostack.length - 1];
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    //判断输入站与输出栈是否都为0
    return this.istack.length == 0 && this.ostack.length == 0;
};
```
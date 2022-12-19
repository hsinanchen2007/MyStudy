### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.stack = [];
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
    if(this.stack.length === 0) return null;
    for(var i = 0; i < this.stack.length - 1; i++){
        this.stack.push(this.stack.shift());
    }
    return this.stack.shift();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if(this.stack.length === 0) return null;
    for(var i = 0; i < this.stack.length - 1; i++){
        this.stack.push(this.stack.shift());
    }
    var tmp = this.stack.shift();
    this.stack.push(tmp);
    return tmp;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    if(this.stack.length === 0) return true;
    return false;
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
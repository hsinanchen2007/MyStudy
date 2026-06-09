### 解题思路

Js的数组是个很好用的东西，本身就支持：
栈方法：pop，push
队方法：shift，unshift

但是感觉这么一来就像作弊。然后我稍微绕个圈子吧。。。

具体实现直接看代码，很简单。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.stack = [];
    this.index = -1;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.index++;
    this.stack[this.index] = x;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.stack[this.index--];
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.stack[this.index];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.index === -1;
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
### 解题思路
利用js的数组来模拟出栈、入栈。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.list = [];
    return this.list;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.list.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const popItem = this.list.pop();
    return popItem;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.top();
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.empty();
};
Array.prototype.top = function() {
  return this[this.length - 1];
};
Array.prototype.empty = function() {
  return this.length === 0;
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
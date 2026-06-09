### 解题思路

首先，明确栈的基本概念：**后进先出**。
在JS中，Array本身就具备了push()、pop()、shift()、unshift()这四种API，可以完美地模拟队列或者栈。
在本题中，push()功能相同，无需变更。
本题的pop需要**移除**栈顶的元素，从数组的角度看，就是移除数组末位元素，即Array.prototype.pop()。
top()则只是**获取**栈顶元素，所以简单地读取数组末尾的元素即可。
empty()用于判空，则直接比较数组长度是否小于等于0即可。

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
    this.stack.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.stack.pop();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.stack[this.stack.length - 1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.stack.length <= 0;
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
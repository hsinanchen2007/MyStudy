### 解题思路
![image.png](https://pic.leetcode-cn.com/48362b2d7e4322009f623fbf7baab1f93bace506386c0048ad2ca1b4bd9b4285-image.png)

两个队列来回翻腾，记下总长度，最后一个就能pop。
### 代码

```javascript
// 225. Implement Stack using Queues

// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Example:

// MyStack stack = new MyStack();

// stack.push(1);
// stack.push(2);  
// stack.top();   // returns 2
// stack.pop();   // returns 2
// stack.empty(); // returns false
// Notes:

// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

/**
 * Initialize your data structure here.
 */
var MyStack = function () {
    this.que = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function (x) {
    this.que.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function () {
    let i = 0,
        tmp = [],
        len = this.que.length;
    while (i <= len - 2) {
        tmp.push(this.que.shift());
        i++;
    }
    let top = this.que.shift();
    this.que = tmp.slice(0);
    return top;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function () {
    let i = 0,
        tmp = [],
        len = this.que.length;
    while (i <= len - 2) {
        tmp.push(this.que.shift());
        i++;
    }
    let top = this.que.shift();
    this.que = tmp.slice(0);
    this.que.push(top);
    return top;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function () {
    return this.que.length === 0;
};

```
### 解题思路

题目中提到，用 ``队列`` 来实现 ``栈``，那么 ``队列`` 和 ``栈`` 分别有什么特点呢？

- ``队列``：先进先出
- ``栈``：后进先出

在 ``JavaScript`` 中数组比较灵活，直接可以当作 ``栈`` 来使用，这里图个方便，只要熟悉 ``数组`` 的基本操作即可：

- ``push`` （将元素添加到 ``数组`` 末尾）
- ``pop``（将 ``数组`` 末尾元素删除并返回）
- ``shift``（将 ``数组`` 首个元素删除并返回）
- ``unshift``（将元素添加到 ``数组`` 首部）

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
    return this.stack.pop()
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.stack[this.stack.length - 1]
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
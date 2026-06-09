### 解题思路
此处撰写解题思路
数组模拟栈,
push -- 在栈的顶端添加元素
pop -- 删除栈顶的元素，既数组最后插入的元素
top -- 获取最后一个插入栈顶的元素，既数组的最后一个元素,实现后进先出

### 代码

```javascript
/**
 * Initialize your data structure here.
 * 
 */
var MyStack = function() {
    this.data = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 * 
 */
MyStack.prototype.push = function(x) {
    this.data.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 *
 */
MyStack.prototype.pop = function() {
  return  this.data.pop()
};

/**
 * Get the top element.
 * @return {number}
 * 
 */
MyStack.prototype.top = function() {
    return this.data[this.data.length -1]
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.data.length === 0
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
### 解题思路
此处撰写解题思路

此处并未使用队列的数据格式, 而是js中的数组, 本身就有两头插入两头挤出的功能. 严格来说不符合题意. 使用队列的数据结构需要双队列, 每次push时需要将新元素push到空队列, 再将原队列的元素一一搬运过来实现, 原队列则作为下次push的空队列, 循环往复.

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.array = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.array.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.array.pop()
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.array[this.array.length - 1]
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.array.length === 0
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
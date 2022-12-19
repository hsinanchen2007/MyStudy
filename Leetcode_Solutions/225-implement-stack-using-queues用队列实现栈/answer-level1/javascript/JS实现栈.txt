### 解题思路
直接利用javascript中数组本身的push、pop等方法来实现，就非常简单了

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.storage = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    return this.storage.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if (this.storage.length > 0) {
        return this.storage.pop();
    }
    return null;

};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    var size = this.storage.length;
    if (size === 0) {
        return null;
    }
    return this.storage[size - 1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    var size = this.storage.length;
    return size === 0;
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
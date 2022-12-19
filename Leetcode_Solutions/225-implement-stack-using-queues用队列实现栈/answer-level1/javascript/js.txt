
### 对于js来说不难，难的是怎么减少时间，提供一种办法作为参考，欢迎提供更优方法，感谢。

```javascript []
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.list = [];
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
MyStack.prototype.truncate = function(arr) {
   return arr.filter(function(v, i, ar) {
      return i !== ar.length - 1
   })
};

MyStack.prototype.pop = function() {
    let res = this.list[this.list.length-1];
    this.list = this.truncate(this.list);
    return res;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.list[this.list.length-1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.list.length === 0;
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

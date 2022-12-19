### 解题思路
此处撰写解题思路
JS中的数组非常灵活，可以利用API来进行实现。
### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
   this.arr = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.arr.unshift(x); 
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
   return this.arr.shift(); 

};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    var a = this.arr[0]
    return a;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.arr.length == 0 ? true:false;
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
### 解题思路
此处撰写解题思路
...emm 就打个卡。。。
拿个数组模拟一下
### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
   this.stack=[]
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.stack[this.stack.length]=x
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    let result = this.stack[this.stack.length - 1];
	this.stack.length = this.stack.length - 1;
	return result;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    let result = this.stack[this.stack.length - 1];
	return result;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
  return !this.stack.length>0
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
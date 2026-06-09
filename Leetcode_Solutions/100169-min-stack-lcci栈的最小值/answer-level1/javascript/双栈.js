### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.Stack = []
  this.minStack = []
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this.Stack.push(x)
  if(!this.minStack.length || (this.minStack.length && this.minStack[this.minStack.length - 1] >= x)){
    this.minStack.push(x)
  }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  let x = this.Stack.pop()
  if(x == this.minStack[this.minStack.length - 1]){
    this.minStack.pop()
  }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.Stack[this.Stack.length - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this.minStack[this.minStack.length - 1]
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
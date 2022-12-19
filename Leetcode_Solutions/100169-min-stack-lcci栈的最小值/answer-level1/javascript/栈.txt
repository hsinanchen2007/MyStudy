### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.list = []
  this.index = 0
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
   this.list[this.index++] = x
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.list.length = --this.index
  
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
 return this.list[this.index - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return Math.min(...this.list)
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
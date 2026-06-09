主要需要每次更新栈里面的最小值
```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.stack = [];
    this.min = -Infinity;
    return this;
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.stack.push(x);
    this.min = Math.min(...this.stack);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.stack.pop();
    this.min = Math.min(...this.stack);
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() { // 这里是获取栈顶的元素
    let top = this.stack[this.stack.length-1];
    this.min = Math.min(...this.stack);
    return top;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
 return this.min;
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
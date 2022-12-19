# 辅助栈
```
var MinStack = function() {
    this.stack = [];
    this.temp = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.stack.push(x);
    if(this.temp.length==0||x<=this.temp[this.temp.length-1]) this.temp.push(x);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if(this.stack.pop() == this.temp[this.temp.length-1]) this.temp.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack.length>0?this.stack[this.stack.length-1]:null;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.temp[this.temp.length-1];
};

```

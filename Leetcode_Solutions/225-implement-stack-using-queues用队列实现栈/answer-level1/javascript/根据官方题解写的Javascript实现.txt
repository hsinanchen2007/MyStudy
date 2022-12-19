### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.list = [];
    this.topEl = null;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.list.push(x);
    this.topEl = x;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    let temp = [];
    while(this.list.length > 1) {
            let s = this.list.shift();
            temp.push(s);
            this.topEl = s;
    }
    let topEl = this.list.shift();
    this.list = temp;
    return topEl;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.topEl
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.list.length === 0
};

/** 
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */

var obj = new MyStack()
obj.push(1)
obj.push(2)
obj.push(3)
obj.push(4)
var param_4 = obj.empty

console.log(param_4);

var param_1 = obj.pop();
console.log(param_1);
console.log(obj);
console.log(obj.top());
```
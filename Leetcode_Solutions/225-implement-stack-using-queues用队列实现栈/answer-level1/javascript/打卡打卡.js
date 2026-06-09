### 解题思路
此处撰写解题思路
本题使用JavaScript中的Array实现队列进而模拟栈。
> Array中队列的操作有：
> 入队：Array.push()
> 出队：Array.shift()
运用Array中常用的操作函数进行实现即可。
### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.que = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    if(!isNaN(x)) {
        this.que.push(x);
    }
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if(!this.empty()) {
        var num = this.top();
        this.que = this.que.slice(-this.que.length, this.que.length-1);
        return num;
    }
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if(this.empty())
        return NaN;
    return this.que[this.que.length - 1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.que.length == 0 ? true : false;
};
```
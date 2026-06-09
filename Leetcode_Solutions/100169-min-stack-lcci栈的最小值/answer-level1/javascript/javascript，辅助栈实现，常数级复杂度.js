执行用时 :  120 ms , 在所有 JavaScript 提交中击败了 83.06% 的用户

内存消耗 : 44.5 MB, 在所有 JavaScript 提交中击败了100.00%的用户


方法：


添加辅助栈，与主栈同步，用来记录最小值。

```
/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.stack = []
    this.helpStack = []
    this.length = 0
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    const len = this.length
    this.stack[len] = x
    if (!len || this.helpStack[len - 1] > x) {
        this.helpStack[len] = x
    } else {
        this.helpStack[len] = (this.helpStack[len - 1])
    }
    this.length = len + 1
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    const len = this.length
    this.length = len - 1
    return this.stack[len -  1]
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack[this.length - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
return this.helpStack[this.length - 1]
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
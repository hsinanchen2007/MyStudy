当 `push` 的时候，将元素包装成 JavaScript 的 Object，同时记录 val（当前元素的值，以及 push 进这个元素后的最小值）。
```
{
    val : 1,
    min : 1
}
```

```jascript
/**
 * initialize your data structure here.
 */
var MinStack = function () {
    this.min = null;
    this.stack = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {

    // 计算该元素 push 后的最小值
    if (this.min === null || x < this.min) {
        this.min = x;
    }
    this.stack.push({
        val: x,
        min: this.min
    })
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    this.stack.pop();
    // 将元素 pop 后重新设置最小值
    this.min = this.getMin();
    
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    if (this.stack.length === 0) {
        return null;
    }
    // 取值的时候要返回 node.val
    return this.stack[this.stack.length - 1].val;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    if (this.stack.length === 0) {
        return null;
    }
    return this.stack[this.stack.length - 1].min;
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

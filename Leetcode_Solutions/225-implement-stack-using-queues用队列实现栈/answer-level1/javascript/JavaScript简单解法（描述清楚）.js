- **在JavaScript里面，没有像C++那样有可用的vector，deque等数据结构，所以只能用数组来模拟队列**
- **好在JavaScript里的数组功能很强大，所以模拟起来非常容易（把数组旋转一个90°，看起来就像一个栈了^-^）**
- **队列：先进先出（FIFO），可以类比显示生活中的排队，栈是反过来的，先进后出**

```
var MyStack = function() {
    //让这个数组成为MyStack这个构造函数的一个属性，这样每次new出来后相当于自带这个数组。
    this.items = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.items.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.items.pop();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.items[this.items.length-1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.items.length ==0;
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


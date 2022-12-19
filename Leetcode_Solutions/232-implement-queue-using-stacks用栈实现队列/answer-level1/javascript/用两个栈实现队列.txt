思路：由于栈是后进先出，队列是先进先出，那么声明两个栈，一个按顺序压入栈为stackPush，再把stackPush栈按顺序全部倒入stackPop栈，stackPop用来弹出栈，就能实现队列的效果了。注意：如果直接调用API，没有使用两个栈的方式，即使能通过也违背了题意。
```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function () {
    this.stackPush = [];
    this.stackPop = [];
};
/**
 * push栈向pop栈倒数据,
 * 确保stackPop为空，stackPush一次性倒完
 */
MyQueue.prototype.pushToPop = function () {
    if (this.stackPop.length === 0) {
        while (this.stackPush.length) {
            this.stackPop.push(this.stackPush.pop());
        }
    }
}
/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
    this.stackPush.push(x);
    this.pushToPop();
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function () {
    if (this.stackPush.length === 0 && this.stackPop.length === 0) {
        throw Error('Queue is empty!');
    }
    this.pushToPop();
    return this.stackPop.pop();
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function () {
    if (this.stackPush.length === 0 && this.stackPop.length === 0) {
        throw Error('Queue is empty!');
    }
    this.pushToPop();
    // 这里注意一下，用js的shift()方法无法通过，因为题目已经说了
    // 只有用 push to top, peek/pop from top, size, 和 is empty 操作才是合法的。
    return this.stackPop[this.stackPop.length - 1];
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function () {
    // 当length = 0 时，0 隐式转换为 false，取反为true
    return !this.stackPush.length && !this.stackPop.length;
};
```
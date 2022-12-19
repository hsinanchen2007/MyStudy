### 解题思路

队列的先进先出原则、堆栈的后进先出原则了解后，可以选择使用两个队列来进行模拟

看意愿是想让push麻烦一点还是pop麻烦一点，题目要求有top的实现，故将push麻烦一点比较合适。

下面的代码是把pop变麻烦的实现（写完了才意识到上面的问题）：

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.queue = [];
    this.size = 0;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.queue.push(x);
    this.size++;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const tempQueue = [];
    // 暂时保存队列的前n-1个元素
    for(let i = 0; i < this.size - 1; i++) {
        tempQueue.push(this.queue.shift());
    }
    // 取出最晚进入队列的第n个元素，原队列已空，新队列剩下n-1个元素
    const val = this.queue.shift();
    this.queue = tempQueue;
    this.size--;
    return val;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    const tempQueue = [];
    for(let i = 0; i < this.size - 1; i++) {
        tempQueue.push(this.queue.shift());
    }
    const val = this.queue.shift();
    this.queue = tempQueue;
    this.queue.push(val);
    return val;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.size;
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

### 其他

我的 GitHub [@ceynri](https://github.com/ceynri) 欢迎访问~

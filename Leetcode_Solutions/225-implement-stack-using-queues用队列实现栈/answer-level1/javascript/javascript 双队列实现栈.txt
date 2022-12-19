### 解题思路

`javascript` 双队列实现栈

q1 为输出队列，q2 为输入队列


### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.q1 = [] // 输出队列
    this.q2 = [] // 输入队列
    this.topnum  // 栈顶元素 
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.topnum = x
    this.q1.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const {q1, q2} = this
    while(q1.length){
        if(q1.length == 1){
            const top = q1.shift()
            this.q1 = q2
            this.q2 = []
            return top
        }
        this.topnum = q1.shift()
        q2.push(this.topnum)
    }
    return -1
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.topnum
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.q1.length
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
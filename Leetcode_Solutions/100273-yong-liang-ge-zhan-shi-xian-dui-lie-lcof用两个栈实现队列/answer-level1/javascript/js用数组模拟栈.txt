### 解题思路
见注释，理解题意很重要。虽然还是看不懂题目给的sample task

### 代码

```javascript
var CQueue = function() {
  this.inStack = [];
  this.outStack = [];
};

/** 
 * @param {number} value
 * @return {void}
 */

CQueue.prototype.appendTail = function(value) {
  this.inStack.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if (this.outStack.length) {
        return this.outStack.pop()
    } else {
        // 将outStack的元素往先进栈推入，该过程相当于reverse排序，把最老的元素摆在了outStack的栈顶
        while (this.inStack.length) {
            this.outStack.push(this.inStack.pop())
        }
        // 取出outStack的栈顶
        return this.outStack.pop() || -1
    }
};


// 注意：js用数组模拟栈，只能进行push和pop操作，即只能操作栈尾（入栈和出栈）
/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
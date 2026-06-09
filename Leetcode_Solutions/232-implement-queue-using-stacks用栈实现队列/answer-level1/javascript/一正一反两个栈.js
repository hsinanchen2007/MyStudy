### 解题思路
![image.png](https://pic.leetcode-cn.com/bc9b8de8f29f8e751638a3d0161d5a57cbc6f4cd2af62b660a17ce350c62218a-image.png)

一正一反两个栈，还有一个临时栈。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function () {
    this.st = [];
    this.reSt = [];
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
    this.st.push(x);
    let stCopy = this.st.slice(0);
    this.reSt = [];
    while (stCopy.length) {
        this.reSt.push(stCopy.pop());
    }

};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function () {
    let tmp = this.reSt.pop(),
        stCopy = this.reSt.slice(0);
    this.st = [];
    while (stCopy.length) {
        this.st.push(stCopy.pop());
    }
    return tmp;
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function () {
    let tmp = this.reSt.pop();
    this.reSt.push(tmp);
    return tmp;
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function () {
    return this.st.length === 0;
};
```
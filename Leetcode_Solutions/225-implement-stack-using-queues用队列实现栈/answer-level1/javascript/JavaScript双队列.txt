### 解题思路
queue1和queue2,当push值时保存队尾元素，pop时将queue1的值存入queue2中并更新队尾元素，当剩下queue1的最后一个元素时，直接返回该元素。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.queue1 = [];
    this.queue2 = [];
    this.topnum;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.topnum = x;
    this.queue1.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const {queue1,queue2} = this;
    while(queue1.length){
        if(queue1.length == 1){
            const tmp = queue1.shift();
            this.queue1 = queue2;
            this.queue2 = [];
            return tmp;
        }
        this.topnum = queue1.shift()
        queue2.push(this.topnum);
    }
    return -1;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.topnum;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.queue1.length;
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
### 大神的代码
两个栈实现队列，要删除队列头部时，将instack弹出存入outstack中，接下来不用管将outstack还给instack，因为不影响instack
```
var CQueue = function() {
    this.inStack = [];
    this.outStack = [];
};
CQueue.prototype.appendTail = function(value) {
    this.inStack.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    // 不知道是es几的一个神奇的用法，这样声明再接下来的使用中，这两个属性前不需要再添加this了
    const {inStack, outStack} = this;
    if(outStack.length) {
        return outStack.pop()
    } else {
        while(inStack.length) {
            outStack.push(inStack.pop())
        }
        return outStack.pop() || -1
    }
};

```

### 利用js原有方法，执行速度慢且不符合题意

```
var CQueue = function() {
    this.queue = [];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.queue.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if(this.queue.length > 0) {
        return this.queue.shift();
    } else {
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
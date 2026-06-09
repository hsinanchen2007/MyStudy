这里自己写的部分使用了es6的小技巧

```
var CQueue = function() {
    this.outStack = []
    this.inStack = []
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
   this.inStack.push(value)
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    <!-- es6的赋值特性 -->
    let {outStack, inStack} = this
    if (!outStack.length) {
        while(inStack.length) {
            outStack.push(inStack.pop());
        }
    }
    <!-- 这里使用短路写法 -->
    return outStack.pop() || -1;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```

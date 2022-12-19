### 解题思路
1.执行appendTail时将元素压入栈1.
2.执行deleteHead时先检查栈2中是否有元素，否则先将栈1中的元素压入栈2中，再将栈2中的元素取出来。

### 代码

```javascript
var CQueue = function () {
        this.inStack = [];
        this.outStack = [];
    };

    /** 
     * @param {number} value
     * @return {void}
     */
    CQueue.prototype.appendTail = function (value) {
        this.inStack.push(value);
    };

    /**
     * @return {number}
     */
    CQueue.prototype.deleteHead = function () {
        const { inStack, outStack } = this;
        if (outStack.length) {
           return outStack.pop();
        }
        else {
            while (inStack.length) {
                outStack.push(inStack.pop());
            }
            return outStack.pop() || -1;
        }
    };

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
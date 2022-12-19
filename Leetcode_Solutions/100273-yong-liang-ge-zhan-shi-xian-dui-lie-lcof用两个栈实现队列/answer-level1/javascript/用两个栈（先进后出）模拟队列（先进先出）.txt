### 解题思路
实现栈的进出只能使用数组尾部方法push()和pop();
对于队头删除操作 利用第二个栈，将第一个栈从尾部开始压入第二个，输出栈底（队头）后，再将第二个栈从尾部压回第一个。

### 代码

```javascript
var CQueue = function() {
    this.pushArr=[];
    this.popArr=[];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    return this.pushArr.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if(this.pushArr.length<=0) return -1;
    if(this.pushArr.length==1) return this.pushArr.pop();
    else {
        while(this.pushArr.length>1){
            this.popArr.push(this.pushArr.pop());
        }
        var res=this.pushArr.pop();
        while(this.popArr.length){
            this.pushArr.push(this.popArr.pop());
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
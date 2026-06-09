### 解题思路
此处撰写解题思路

### 代码

```javascript
var CQueue = function() {
    //入栈
    this.isStall = [];
    //出栈
    this.outStall = []
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    //进入队列
    this.isStall.push(value)
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if(this.outStall.length>0){
       //出队列
        return this.outStall.pop()
    }else{
       //准备出队列，先把入的队列的元素一一从头进入出队列中
        while(this.isStall.length>0){
            this.outStall.push(this.isStall.pop())
        }

        return this.outStall.pop()||-1
    }
};

/** 
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
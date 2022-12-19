### 解题思路
此处撰写解题思路

### 代码

```javascript
var CQueue = function() {
    this.stack1 = [];
    this.stack2 = [];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.stack1.push(value)
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    const {stack1, stack2} = this;
    if(stack2.length === 0){
        if(stack1.length === 0){
            return -1
        }else{
            let len = stack1.length;
            for(let i=0;i<len;i++){
                stack2.push(stack1.pop())
            }
            return stack2.pop()
        }
    }else{
        return stack2.pop()
    }
};

/** 
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
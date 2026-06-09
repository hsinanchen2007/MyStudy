### 解题思路
此处撰写解题思路

### 代码

```javascript
var CQueue = function() { 
    this.arrValue = [];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.arrValue.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    let len = this.arrValue.length;
    let _this = this;
    let arr = [];
    if(len == 0) return -1;
    for(let i=0;i<len-1;i++){
        arr.push(_this.arrValue.pop());
    }
    let result = this.arrValue.pop();
    for(let i=0;i<len-1;i++){
        _this.arrValue[i] = arr[len-2-i];
    }
    return result;  
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
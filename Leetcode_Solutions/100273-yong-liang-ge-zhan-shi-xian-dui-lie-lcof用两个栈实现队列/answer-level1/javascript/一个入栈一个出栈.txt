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
  this.stack1.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
  if(this.stack1.length === 0 && this.stack2.length === 0) {
      return -1;
  }
  if(this.stack2.length === 0) {
      while(this.stack1.length!==0) {
          this.stack2.push(this.stack1.pop());
      }
      return this.stack2.pop();
  } else {
    return this.stack2.pop();
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```
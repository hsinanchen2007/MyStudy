### 解题思路
使用链表保存从小打大的节点，第一次push初始化链表头节点值

### 代码

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.data = []
    this.min = {
        val:0,
        prev:null
    }
    this.head = this.min
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.data.push(x)
    if(this.data.length===1){
        this.min.val = x
        return;
    }
    if(this.min.val>=x){
        this.min = {
            val:x,
            prev:this.min
        }
        return
    }
    this.head.prev = {
        val:x,
        prev:null
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if(this.data.pop()===this.min.val){
        this.min = this.min.prev
    }
    
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.data[this.data.length-1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.min.val
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
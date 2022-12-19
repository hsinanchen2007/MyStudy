### 解题思路
打卡

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.queue1 = [];
    this.queue2 = [];
    this.now = 1;
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    if(this.now == 1){
        this.queue1.push(x);
    }else{
        this.queue2.push(x);
    }
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if(this.now == 1){
        while(this.queue1.length > 1){
            this.queue2.push(this.queue1.shift())
        }
        this.now = 2;
        return this.queue1.shift();
    }else{
        while(this.queue2.length > 1){
            this.queue1.push(this.queue2.shift())
        }
        this.now = 1;
        return this.queue2.shift();
    }
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if(this.now == 1){
        while(this.queue1.length > 1){
            this.queue2.push(this.queue1.shift())
        }
        var t = this.queue1.shift();
        this.queue2.push(t)
        this.now = 2;
        return t
    }else{
        while(this.queue2.length > 1){
            this.queue1.push(this.queue2.shift())
        }
        var t = this.queue2.shift();
        this.queue1.push(t)
        this.now = 1;
        return t
    }
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.queue1.length && !this.queue2.length
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
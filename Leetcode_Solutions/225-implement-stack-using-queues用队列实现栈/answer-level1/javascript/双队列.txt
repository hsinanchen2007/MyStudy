### 解题思路

利用双队列

queue1 保存除队尾的其他元素
queue2 保存队尾元素也就是栈顶

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.queue1 = [];
    this.queue2 = [];
};
MyStack.prototype.transfrom = function(){
    while(this.queue1.length !== 1){
        this.queue2.push(this.queue1.shift());
    }
    let a = this.queue1;
    this.queue1 = this.queue2;
    this.queue2 = a;
}
/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    if(!this.queue2.length){
        this.queue1.push(x)
    }else{
        this.queue2.push(x);
        this.queue1.push(this.queue2.shift());
    }
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if(!this.queue2.length) this.transfrom();
    return this.queue2.shift();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if(!this.queue2.length) this.transfrom();
    return this.queue2[0];
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
### 解题思路
用this.list = []建一个数组，之后用this.list调用数组
模拟入栈用数组的push()方法，
模拟出栈先模拟队列出队到队尾给数组tmp，输出队尾元素给a，将数组tmp赋回给list，返回a
模拟取栈顶：取数组长度this.list.length,栈顶元素为数组最后一个元素this.list[this.list.length-1]
模拟判空：取数组长度this.list.length,数组长度==0，说明数组为空

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.list = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.list.push(x)
    // 他人用的非api的方法
    // this.list[this.list.length]=x

};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if(this.list.length!=0){
        return this.list.pop()
        // 他人用的非api的方法
        // let a=this.list[this.list.length-1]
        // this.list.length--
        // return a
    }
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if(this.list.length!=0){
        return this.list[this.list.length-1]
    }
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return (this.list.length==0)
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
### 解题思路
利用JavaScript中自带的数组方法push和pop方法进行在入栈和出栈操作

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.stack = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    //元素在栈顶入栈;执行push操作
     return this.stack.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    //删除栈顶元素；pop操作
return this.stack.pop();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
//返回栈订元素，即最后一个元素，length-1
 return this.stack[this.stack.length-1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
//判断栈是否为空，为空则返回true，否则返回false（根据数组的长度判断）
    if(this.stack.length<1){
        return true;
    }
    else{
        return false;
    }
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
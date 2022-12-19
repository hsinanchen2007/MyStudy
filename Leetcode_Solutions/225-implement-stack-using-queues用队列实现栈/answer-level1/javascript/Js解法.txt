### 解题思路Js版
stack数据结构中维护两个数组。在一个操作完成后，始终有一个数组为空，另一个不为空的数组，存储数据的顺序与栈的顺序相同。
1. push: 向不为空的数组尾部push即可(对应queue的push)
2. pop: 假设操作开始前a数组不为空，则将a数组的所有数据(除了最末一个)shift到b数组中(对应queue的pop front)，再将最后一个数据shift并返回即可
3. top: 与pop同理。区别在于top并不将栈顶端元素移除。
4. empty: a为空且b为空时，栈为空。所以应该返回`!a.length && !b.length` 或者 `!(a.length || b.length)`


### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
        this.a = [];
        this.b = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    if (this.a.length) {
        this.a.push(x);
    } else {
        this.b.push(x);
    }
    
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if (this.a.length) {
        while(this.a.length != 1) {
            this.b.push(this.a.shift());
        }

        return this.a.shift();
    } else {
        while(this.b.length != 1) {
            this.a.push(this.b.shift());
        }

        return this.b.shift();
    }
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    let top; 
    if (this.a.length) {
        while(this.a.length != 1) {
            this.b.push(this.a.shift());
        }
        top = this.a.shift();
        this.b.push(top);
    } else {
        while(this.b.length != 1) {
            this.a.push(this.b.shift());
        }
        top = this.b.shift();
        this.a.push(top);
    }
    return top;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !(this.a.length || this.b.length);
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
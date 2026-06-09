### 解题思路
首先明确**队列**和**栈**的属性：

- 队列：尾进头出，也就对应JavaScript中数组的`push`和`shift`
- 栈：尾进尾出，对应JavaScript中数组的`push`和`pop`

关于`push`的操作是相同的，所以此题也可转换为：使用`push`和`shift`实现`pop`、`top`。



由于队列属性的限制，所以想要获取q1队尾的元素，只能先把q1前面的元素逐一出队，知道q1长度为1，则返回该元素。为了保存q1队尾前的元素，引入q2作为辅助队列。

### 代码

```javascript
var MyStack = function() {
    this.q1=[];
    this.q2=[];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.q1.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    while(this.q1.length>1){
        this.q2.push(this.q1.shift())
    }
    let res=this.q1.shift();
    this.q1=this.q2;
    this.q2=[];
    return res;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    while(this.q1.length>1){
        this.q2.push(this.q1.shift())
    }
    let res=this.q1.shift();
    this.q2.push(res);
    this.q1=this.q2;
    this.q2=[];
    return res;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.q1.length==0;
};
```
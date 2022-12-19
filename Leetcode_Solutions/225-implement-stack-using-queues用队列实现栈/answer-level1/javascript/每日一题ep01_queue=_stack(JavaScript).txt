### 解题思路
**栈**(stack) ,它是一种受限的线性表,**后进先出**(LIFO, last in first out)
其限制是仅允许在表的一端进行插入和删除运算，这一端称为栈顶,另一端为栈底。
向一个栈插入新元素为进栈,使其成为新的栈顶元素。
从一个栈删除元素为出栈，使其相邻的元素成为新的栈顶元素。

**队列**(Queue),它是一种受限的线性表,**先进先出**(FIFO, First In First Out)
只允许在表的前端(front)进行删除操作,而在表的后端(rear)进行插入操作。

鉴于JS中没有stack和queue，所以调用**数组API**来实现。
注意到**对一个空的栈不会调用 pop 或者 top 操作**,所以在pop和top中都加入一个!this.empty()的判断。

### 代码

```javascript

var MyStack = function() {
    this.stack =[]

};

MyStack.prototype.push = function(x) {
    this.stack.push(x)
};

MyStack.prototype.pop = function() {
    if(!this.empty()){
        return this.stack.pop()
    }
};

MyStack.prototype.top = function() {
    if(!this.empty()){
       return this.stack[this.stack.length - 1] 
    } 
};

MyStack.prototype.empty = function() {
    return this.stack.length === 0
};

```
😎
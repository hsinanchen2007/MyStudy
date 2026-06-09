
最近看了数据结构与算法才了解到：栈先入后出 最形象例子就是叠盘子 洗干净早的会叠放在最下面，后获取的时候都是拿到最上面的(也就是最新添加的)。

```
var MyStack = function() {
    this.dataStore = [];// 初始化数据盒子
    this.h_top = 0; //初始化变量记录栈顶位置
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.dataStore[this.h_top++] = x;// 这里的意思是 h_top先自增一个高度。 然后dataStore的最新高度h_top 的位置赋值为x
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.dataStore[--this.h_top]
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.dataStore[this.h_top-1]
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.h_top==0;
};

```


应该是js的没什么人提交吧~ 
执行用时 :52 ms, 在所有 JavaScript 提交中击败了95.71%的用户; 
内存消耗 :33.5 MB, 在所有 JavaScript 提交中击败了96.91%的用户

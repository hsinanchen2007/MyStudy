### 解题思路
好吧是一只菜鸡。打卡第一天

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var queue1 = []
var queue2 = []
var MyStack = function() {
    
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    var queue = [] //定义一个队列
    queue.push(x)
    return queue
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {//移除栈顶元素
   // var queue1 = []
   // var queue2 = []
    if(queue1.length == 0) return false
    while(queue1.length){
        if(queue1.length == 1){
            var q = queue1.poll()
            return q
        }
        var p = queue1.poll()
        queue2.push(p)     
    }
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {//获取栈顶元素
    //var queue1 = []
   // var queue2 = []
    if(queue1.length == 0) return false
    while(queue1.length){
        if(queue1.length == 1){
            var q = queue1.poll()
            queue2.push(q)
            return q
        }
        var p = queue1.poll()
        queue2.push(p)
        //return queue2
    }
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    var queue = []
    if(queue.length == 0){
        return false
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
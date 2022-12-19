### 解题思路
方法一、定义两个数组表示栈

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function() {
   this.stack1=[];//数据都保存在stack1
   this.stack2=[];//数据从stack1出栈进入stack2
   
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    this.stack1.push(x);
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    if(this.stack2.length){//如果stack2不为空，说明数据全都移入了stack2，直接pop操作移除stack2的最后一位即为stack1 的第一位
        return this.stack2.pop();
    }else{
        if(this.stack1.length){//如果stack1不为空
            var len = this.stack1.length;
            for(var i=0;i<len;i++){
                this.stack2.push(this.stack1.pop());//将元素全部移入到stack2
            }
            return this.stack2.pop()//pop操作移除stack2的最后一位即为stack1 的第一位
        }else{
             return null
        }
         
    }
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    if(this.stack1.length==0){
        return this.stack2[this.stack2.length-1]
    }else if(this.stack2.length==0)
    return this.stack1[0];
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    if(this.stack1.length==0&& this.stack2.length==0){//只有当两个stack均为空的时候才能证明队列为空
        return true;
    }else {
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
```
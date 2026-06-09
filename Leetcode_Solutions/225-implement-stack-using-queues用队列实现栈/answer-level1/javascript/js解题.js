### 解题思路
题目要求我们只能用队列来实现栈

在js中没有队列这个类型，用数组可以模拟，但是队列是先进先出，所以数组的api我们只能用push()和shift()来完成

进栈操作是一样的，所以直接push即可

出栈是栈顶出去(即队尾出列)，所以这里必须需要一个辅助队列来完成，把队列的所有元素放进辅助队列，然后将辅助队列(最后一个元素不放入)再放入队列，就完成了出栈操作。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
  this.queue = [],
  this.q = []
  this.length = 0
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
  this.queue.push(x)
  this.length += 1
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
  if (this.empty())  return false
  this.length -= 1
  var cur = null;
  while(cur = this.queue.shift()) {  //将队列的所有元素取出放在q中
    this.q.push(cur)
  }
  var len = this.q.length  //3 -1 = 2   0 1 
  for (let i = 0; i < len - 1 ; i++) {  //将q中的元素减一放入queue中 
    cur = this.q.shift()
    // console.log(cur)
    this.queue.push(cur)
  }
  // console.log(this.queue)
  // console.log(this.queue)
  return this.q[0]
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
  if (this.empty()) return false
  return this.queue[this.queue.length - 1]
};  

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
  return this.length == 0
};
```
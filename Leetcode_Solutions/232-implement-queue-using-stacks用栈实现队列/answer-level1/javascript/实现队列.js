### 解题思路
这题只要对数组的几个APi熟悉的话很简单。

入列 push()  出列shift() 判断空 判断queue的长度即可。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function() {
  this.queue = []
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
  this.queue.push(x);
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function() {
  return this.queue.shift()
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function() {
  if (this.empty()) return false
  return this.queue[0]
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
  return this.queue.length == 0 ? true : false
};
```
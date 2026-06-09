### 解题思路
在每次 push 的时候，重新调整整个 queue 的顺序

```
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
  this.queue = []
}

/**
 * Push element x onto stack.
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
  const size = this.queue.length
  this.queue.push(x)
  for (let i = 0; i < size; i++) {
    this.queue.push(this.queue.shift())
  }
}

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
  return this.queue.shift()
}

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
  return this.queue[0]
}

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
  return this.queue.length === 0
}
```


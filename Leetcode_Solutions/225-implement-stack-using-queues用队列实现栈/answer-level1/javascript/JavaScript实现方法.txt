### 解题思路
此处撰写解题思路

### 代码

```javascript
var MyStack = function() {
  this.queue = []
};

MyStack.prototype.push = function(x) {
  this.queue.push(x)
  let size = this.queue.length
  while (size > 1) {
    this.queue.push(this.queue.shift())
    size--
  }
};


MyStack.prototype.pop = function() {
  return this.queue.shift()
};


MyStack.prototype.top = function() {
  return this.queue[0]
};


MyStack.prototype.empty = function() {
  return !this.queue.length
};
```
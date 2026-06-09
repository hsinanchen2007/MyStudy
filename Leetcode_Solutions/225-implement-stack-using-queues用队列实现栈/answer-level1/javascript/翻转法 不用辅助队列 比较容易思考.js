### 解题思路
在javascript中，用数组模拟队列，就是用shift()表示出队，push()表示入队。
再次限制下模拟栈，就是模拟pop()出栈，top()因为没有取队列第一个元素的原生方法，在此用下标[0]表示。

我们让队列的元素保持反转，再出队shift()，就和pop()一样了。
比如模拟栈1234，辅助队列的元素4321；
模拟pop()的时候，直接shift()就是4出队变成321；
现在队列是321；
模拟push(5)的时候，我们先让辅助队列反转为123，在push(5)，变为1235，再反转回队列5321。

push的时候我们反转两次队列，复杂度为O(n) + O(1)；
pop和shift的复杂度一样。

### 代码

```javascript

var MyStack = function() {
  this.queue = []
};

MyStack.prototype.push = function(x) {
  this.queue.reverse()
  this.queue.push(x)
  this.queue.reverse()
};

MyStack.prototype.pop = function() {
  return this.queue.shift()
};

MyStack.prototype.top = function() {
  return this.queue[0]
};

MyStack.prototype.empty = function() {
  return this.queue.length === 0
};

```
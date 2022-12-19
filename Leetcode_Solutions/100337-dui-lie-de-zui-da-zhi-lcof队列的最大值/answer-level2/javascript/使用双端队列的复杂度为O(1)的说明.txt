先贴实现：

```javascript
var MaxQueue = function() {
  this.queue = []
  this.dequeue = []
}
MaxQueue.prototype.max_value = function() {
  if (this.queue.length === 0) return -1
  return this.dequeue[0]
}
MaxQueue.prototype.push_back = function(value) {
  this.queue.push(value)
  while (this.dequeue[this.dequeue.length - 1] < value) {
    this.dequeue.pop()
  }
  this.dequeue.push(value)
}
MaxQueue.prototype.pop_front = function() {
  if (this.queue.length === 0) return -1
  const value = this.queue.shift()  
  if (value === this.dequeue[0]) {
    this.dequeue.shift()    
  }
  return value
}
```
这里用了JS自带的数组做作为队列，我们就默认它的shift和pop复杂度为O(1)吧（实在不行也可以自行实现双端队列，问题不大）

解法也是和官方题解一模一样的，唯一可能有疑问的地方就是`push_back`这个操作，里面有个循环，怎么复杂度就是O(1)了呢？

再怎么说明也不如实际举例来得清楚。首先要注意的是，题目要求的复杂度是**均摊复杂度**。 什么意思呢？就是你具体的某一步出队或入队操作，不一定只能执行常数次操作。但所有的操作加起来，不能超过O(n)。

比如我们向队列中依次push了这些数字: [n, n-1, n-2, ... 0], 如果我们再push一个 n + 1进去，将会执行n次出队操作，这次操作的复杂度是O(n)。但是如果我们计算下从一开始到最后总共的出队操作次数呢？总共也只有n次（之前一次都没有执行过出队操作），所以均摊到每一步上的复杂度，是O(1)。
 

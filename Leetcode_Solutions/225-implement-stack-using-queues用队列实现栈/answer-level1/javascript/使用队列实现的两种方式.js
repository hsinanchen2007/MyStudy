### 解题思路

要用队列实现栈，有两种方法：

1. 在进栈时，队列正常入队；在出栈时，对队列的所有元素出队，拿到最后一个元素，把其余的放回队列，并返回最后一个元素。 入栈时间复杂度：O(1) 出栈时间复杂度：O(n)
2. 在进栈时，把元素添加到队首中；在出栈时，直接出队即可。 入栈时间复杂度：O(n) 出栈时间复杂度：O(1)

两种方法都可行，具体实现取决于场景，这里使用第二种方法（出栈使用的较多）。

### 代码

```javascript
class Queue {
  constructor() {
    this.queue = [];
  }

  /**
   * @param {number} x
   * @return {void}
   */
  enqueue(x) {
    this.queue.push(x);
  }

  /**
   * @return {number}
   */
  peek() {
    return this.queue[0];
  }

  /**
   * @return {void}
   */
  dequeue() {
    this.queue.shift();
  }

  /**
   * @return {boolean}
   */
  isEmpty() {
    return this.queue.length === 0;
  }
}

/**
 * Initialize your data structure here.
 */
var MyStack = function() {
  this.queue = new Queue();
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
  const queue = new Queue();

  queue.enqueue(x);

  while (!this.queue.isEmpty()) {
    queue.enqueue(this.queue.peek());

    this.queue.dequeue();
  }

  this.queue = queue;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
  const x = this.queue.peek();
  this.queue.dequeue();

  return x;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
  return this.queue.peek();
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
  return this.queue.isEmpty();
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

#### 复杂度分析

* 时间复杂度：
  * `push`：$O(n)$
  * `pop`：$O(1)$
  * `top`：$O(1)$
  * `empty`：$O(1)$

* 空间复杂度：
  * `push`：$O(n)$ 使用了一个新的队列。
  * `pop`：$O(1)$
  * `top`：$O(1)$
  * `empty`：$O(1)$

### 解题思路

维持两个队列，用与栈的 pop 和top操作。

#### 实现队列的方法

- queue_isEmpty(queue) 判断queu是否为空
- queue_push(queue, x) 向队列queue中插入元素x
- queue_pop(queue)  弹出队列的头元素
- queue_peek(queue) 返回队列的头元素

#### 用队列实现栈

逻辑比较简单，具体看以下代码

### javascript 的实现

```javascript
function queue_isEmpty(queue) {
    return queue.length === 0
  }
function queue_push(queue, x) {
    queue.push(x)
  }
function queue_pop(queue){
    return queue.shift()
  }
function queue_size(queue){
    return queue.length
  }
function queue_peek(queue){
    return queue[0]
}
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
   this.queue = []
   this.queue_bak = []
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    queue_push(this.queue, x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    while (queue_size(this.queue) > 1) {
      queue_push(this.queue_bak, queue_pop(this.queue))
    }
    ;[this.queue, this.queue_bak] = [this.queue_bak, this.queue]
    return queue_pop(this.queue_bak)
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    var ans
    while (queue_size(this.queue) > 0) {
      ans = queue_pop(this.queue)
      queue_push(this.queue_bak, ans)
    }
    ;[this.queue, this.queue_bak] = [this.queue_bak, this.queue]
    return ans
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return queue_isEmpty(this.queue)
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

### typescript 的实现

```typescript
class MyStack<T> {
  private queue: T[] = []
  private queue_bak: T[] = []

  private queue_isEmpty(queue: T[]): boolean {
    return queue.length === 0
  }
  private queue_push(queue: T[], x: T) {
    queue.push(x)
  }
  private queue_pop(queue: T[]): T | undefined {
    return queue.shift()
  }
  private queue_size(queue: T[]): number {
    return queue.length
  }
  private queue_peek(queue: T[]): T | undefined {
    return queue[0]
  }
  /**
   * Push element x onto stack.
   * @param {T} x
   * @return {void}
   */
  push(x: T): void {
    this.queue_push(this.queue, x)
  }

  /**
   * Removes the element on top of the stack and returns that element.
   * @return {T}
   */
  pop(): T {
    while (this.queue_size(this.queue) > 1) {
      this.queue_push(this.queue_bak, this.queue_pop(this.queue) as T)
    }
    ;[this.queue, this.queue_bak] = [this.queue_bak, this.queue]
    return this.queue_pop(this.queue_bak) as T
  }

  /**
   * Get the top element.
   * @return {T}
   */
  top(): T | undefined {
    let ans: T | undefined
    while (this.queue_size(this.queue) > 0) {
      ans = this.queue_pop(this.queue) as T
      this.queue_push(this.queue_bak, ans)
    }
    ;[this.queue, this.queue_bak] = [this.queue_bak, this.queue]
    return ans
  }

  /**
   * Returns whether the stack is empty.
   * @return {boolean}
   */
  empty(): boolean {
    return this.queue_isEmpty(this.queue)
  }
}

```
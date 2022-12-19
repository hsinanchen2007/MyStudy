`使用双链表模拟堆栈结构，不使用数组`

注意点：
1. 每次入栈压入两个节点，一个是表示栈顶，一个是表示当前最小值的节点
2. pop出时每次出两个节点
3. 压入新的最小值节点时可以直接与当前栈的最小值节点比较
4. 空间换时间的概念，栈的空间消耗比较大


```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.stack = null;
  this.min = null;
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  if (this.stack !== null) {
    this.min.next = new Node(x);
    this.min.next.prev = this.min;
    this.stack = this.min.next;
  } else {
    this.stack = new Node(x);
    this.stack.next = null;
    this.stack.prev = null;
  }
  if (this.min !== null) {
    if (x <= this.min.val) {
      this.stack.next = new Node(x);
    } else {
      this.stack.next = new Node(this.min.val);
    }
    this.stack.next.prev = this.stack;
    this.min = this.stack.next;
  } else {
    this.min = new Node(x);
    this.min.prev = this.stack;
    this.stack.next = this.min;
  }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.min.prev = null;
  this.stack.next = null;
  this.min = this.stack.prev;
  this.stack.prev = null;
  if (this.min !== null) {
    this.min.next = null;
    this.stack = this.min.prev;
  } else {
    this.stack = null;
  }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.stack.val;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this.min.val;
};
  
function Node(val) {
  this.val = val;
  this.next = null;
  this.prev = null;
}

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
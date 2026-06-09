### 两个栈操作

具体可看[这里](https://leetcode-cn.com/problems/min-stack/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-38/)

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this._stack = [];
  this._minStack = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this._stack.push(x);
  if (!this._minStack.length) {
    this._minStack.push(x);
  } else {
    if(x <= this.getMin()) {
      this._minStack.push(x);
    }
  }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  const pop = this._stack.pop();
  const result = this.getMin();
  if (pop === result) {
    this._minStack.pop();
  }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this._stack[this._stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this._minStack[this._minStack.length - 1];
};
```

### 跑题练习：直接使用数组方法操作栈

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.stack = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this.stack.push(x);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.stack[this.stack.length-1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return Math.min(...this.stack);
};
```

### 跑题练习：使用对象

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this._count = 0;
  this._items = {};
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this._items[this._count] = x;
  this._count++;
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  if (this._count === 0) return false;
  this._count--;
  delete this._items[this._count];
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this._items[this._count - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  let value = this._items[0];
  for (let i = 1; i < this._count; i++) {
    if (this._items[i] < value) {
      value = this._items[i];
    }
  }
  return value
};
```
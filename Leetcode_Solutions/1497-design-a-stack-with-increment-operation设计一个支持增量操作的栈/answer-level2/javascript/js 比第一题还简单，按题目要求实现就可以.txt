![image.png](https://pic.leetcode-cn.com/d00a5c5449090933e0e01d8f29a46a51d2dcec63745ece811e6b5b1d59b2f74d-image.png)

### 解题思路


### 代码

```javascript
/**
 * @param {number} maxSize
 */
var CustomStack = function(maxSize) {
  this.stack = [];
  this.maxSize = maxSize;
};

/** 
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
  let stack = this.stack;
  if (stack.length < this.maxSize) {
    stack.push( x );
  }
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
  let stack = this.stack;
  if (stack.length > 0) return stack.pop();
  return -1;
};

/** 
 * @param {number} k 
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
  let stack = this.stack;
  for (let i = 0; i < Math.min(stack.length, k); i++) {
    stack[i] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */
```
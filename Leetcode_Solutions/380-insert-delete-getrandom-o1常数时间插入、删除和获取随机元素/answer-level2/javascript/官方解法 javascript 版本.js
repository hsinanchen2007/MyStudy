### 解题思路

大家好，我是 17

题目要求常数时间，存取，删除，可选的是哈希表。
又说，需要常数时间随机元素，可选的是数组。
所以两个都用呗。

值得一提的是，删除的办法很巧妙，做到了常数级。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var RandomizedSet = function () {
  this.map = new Map()
  this.arr = []
};

/**
 * Inserts a value to the set. Returns true if the set did not already contain the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
  if (this.map.has(val)) {
    return false
  }
  else {
    this.arr.push(val)
    this.map.set(val, this.arr.length - 1)
    return true
  }
};

/**
 * Removes a value from the set. Returns true if the set contained the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
  if (this.map.has(val)) {
    let index = this.map.get(val);
    let lastVal = this.arr[this.arr.length - 1]
    this.arr[index] = lastVal
    this.arr.pop()
    this.map.set(lastVal, index)
    this.map.delete(val)
    return true
  }
  else {
    return false
  }
};

/**
 * Get a random element from the set.
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
  let r = Math.floor(Math.random() * this.arr.length)
  return this.arr[r]
};

```
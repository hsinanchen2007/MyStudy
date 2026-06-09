### 解题思路
push：将数组长度位置的值设为x；
pop：使用es6拓展运算符，得出第一个和后面的元素，返回第一个元素，更新数组为除了第一个元素外的其他元素组成的数组。

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyQueue = function() {
    this.arr = [];
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    // this.arr.push(x);
    this.arr[this.arr.length] = x
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    // return this.arr.shift() ;
    let [a, ...newArr] = this.arr;
    this.arr = newArr;
    return a;
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    return this.arr[0];
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    if(this.arr.length == 0) return true;
    return false;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
```
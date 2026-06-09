### 解题思路
![image.png](https://pic.leetcode-cn.com/40ac894c2f5178f21e41722e9fd25294cf72f73d8d0ee1d9d8e018ff946979dd-image.png)

就想到用一个sorted array，每次push都排下序，肯定慢啊。。让我看看高手的题解。。。


### 代码

```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function () {
    this.st = [];
    this.sorted = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
    this.st.push(x)
    this.sorted.push(x);
    this.sorted.sort((a, b) => a - b);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    const p = this.st.pop();
    this.sorted.splice(this.sorted.indexOf(p), 1);
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    return this.st[this.st.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    return this.sorted[0];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
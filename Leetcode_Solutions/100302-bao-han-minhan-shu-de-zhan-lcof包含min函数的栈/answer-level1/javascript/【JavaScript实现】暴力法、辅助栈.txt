
## 解法 1: 暴力法

直接遍历栈得到最小的元素，但理论上 min 函数的时间复杂度是 O(N)，**不符合题目要求，但可以 ac**。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
// 原文地址：https://xxoo521.com/2020-01-31-stack-min/

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
    const length = this.stack.length;
    if (length) {
        return this.stack[length - 1];
    } else {
        return null;
    }
};

/**
 * @return {number}
 */
MinStack.prototype.min = function() {
    const length = this.stack.length;
    if (!length) return null;
    return Math.min(...this.stack);
};
```

## 解法 2: 辅助栈

正确的做法是借助一个辅助栈。他们之间有一种对应关系：辅助栈的栈顶元素，就是原栈所有元素的最小值。

对原栈和辅助栈的处理过程如下：

-   元素压入原栈的时候，如果辅助栈为空，或者`元素 <= 辅助栈的栈顶元素`，那么将元素也压入辅助栈
-   元素弹出原栈的时候，如果元素等于辅助栈的栈顶元素，辅助栈也弹出元素

这里的判断条件是`元素 <= 辅助栈的栈顶元素`而不是`元素 < 辅助栈的栈顶元素`，是为了应对重复元素。例如将 1、2、3、1 依次入栈，采用错误的判断条件，那么辅助栈里面只有 1。在原栈弹出 1 之后，辅助栈为空，就没法获得原栈元素的最小值。

```javascript
// ac地址：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
// 原文地址：https://xxoo521.com/2020-01-31-stack-min/

/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.dataStack = [];
    this.minStack = []; // 辅助栈
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.dataStack.push(x);

    const length = this.minStack.length;
    if (!length) {
        this.minStack.push(x);
    } else if (x <= this.minStack[length - 1]) {
        this.minStack.push(x);
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    const { minStack, dataStack } = this;
    if (minStack[minStack.length - 1] === dataStack[dataStack.length - 1]) {
        minStack.pop();
    }

    dataStack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    const length = this.dataStack.length;
    if (length) {
        return this.dataStack[length - 1];
    } else {
        return null;
    }
};

/**
 * @return {number}
 */
MinStack.prototype.min = function() {
    const length = this.minStack.length;
    if (!length) return null;
    return this.minStack[length - 1];
};
```

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**

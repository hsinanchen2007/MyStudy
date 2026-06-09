
用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。 队列中的元素为 int 类型。

## 解法: 利用栈的特性

栈的特性是：后入先出。根据题目提示，使用 2 个栈即可。一个栈`inStack`用来存储插入队列的数据，一个栈`outStack`用来从队列中取出数据。

算法分为入队和出队过程。

**入队过程**：将元素放入 inStack 中。

**出队过程**：

-   outStack 不为空：弹出元素
-   outStack 为空：将 inStack 元素依次弹出，放入到 outStack 中（在数据转移过程中，顺序已经从后入先出变成了先入先出）

时间复杂度是 O(N)，空间复杂度是 O(N)。

```javascript
// ac地址：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
// 原文地址：https://xxoo521.com/2019-12-23-zhan-shi-xian-dui-lie/

var CQueue = function() {
    this.inStack = [];
    this.outStack = [];
};

/**
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.inStack.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    const { inStack, outStack } = this;
    if (outStack.length) {
        return outStack.pop();
    } else {
        while (inStack.length) {
            outStack.push(inStack.pop());
        }
        return outStack.pop() || -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```


## 拓展思考：用两个队列实现一个栈

类似地，用两个队列也可以实现一个栈。但由于队列是先入先出，无论怎么倒换，都不可能逆序队列。所以处理思路并不一样。

准备两个队列`q1`和`q2`。算法过程分为入栈和出栈。

**入栈过程**：

-   q1 为空，放入 q2
-   q2 为空，放入 q1
-   均为空，默认放入 q1

**出栈过程**：

-   q1 为空：
    -   依次取出 q2 中的元素（除了最后一个），并且放入 q1 中
    -   取出 q2 中的最后一个元素，返回结果
-   q2 为空：
    -   依次取出 q1 中的元素（除了最后一个），并且放入 q2 中
    -   取出 q1 中的最后一个元素，返回结果

时间复杂度是 O(N)，空间复杂度是 O(N)。

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**


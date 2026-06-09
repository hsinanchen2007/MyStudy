
## 解法：辅助队列

使用两个队列，一个队列 queue 用于存放所有元素，另一个辅助队列 dequeue 用来存放当前 queue 中的最大值。

push 操作：

-   将元素放入 queue 中
-   检查元素是否大于 dequeue 队尾元素，如果大于，那么队尾元素出队；直到不再满足大于条件

pop 操作：

-   如果 queue 的队首元素等于 dequeue 的队首元素，那么 dequeue 队首元素需要出队
-   queue 队首元素需要出队

题目要求复杂度控制在$O(1)$，所以必须使用双端队列来做辅助队列。因为 push 操作中，需要频繁对辅助队列的队尾元素进行移动操作。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
// 原文地址：https://xxoo521.com/2020-03-28-max-queue/
var MaxQueue = function() {
    this.queue = [];
    this.dequeue = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.dequeue.length ? this.dequeue[0] : -1;
};

/**
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.queue.push(value);
    while (
        this.dequeue.length &&
        value > this.dequeue[this.dequeue.length - 1]
    ) {
        this.dequeue.pop();
    }
    this.dequeue.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if (!this.dequeue.length) {
        return -1;
    }
    if (this.queue[0] === this.dequeue[0]) {
        this.dequeue.shift();
    }
    return this.queue.shift();
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**

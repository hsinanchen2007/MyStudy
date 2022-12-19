![3XSl36.png](https://pic.leetcode-cn.com/5823de5df29d72f4630189af950c08f7d072e6d3eaec2a47858d7019a5a4272e.png)

（中午十二点的高峰期提交，能有这么低的执行用时也是幸运）

### 解题思路

看了眼评论，大家都说这个题读不懂啊，不过我倒是一下读出来了（对不起），应该是之前做过这种描述的题目的原因。有读不懂的可以翻翻评论或者题解，有人详细解释了样例的意思。

另外就是在取最大值的问题上，很多人用的`Math.max(...queue)`，虽然的确简洁又漂亮哈，但是确实是`O(n)`的复杂度，已经不符合题目限制了，如果题目故意搞些极端的样例，让`O(n)`的算法时间超限，就无法成功提交了。

参考了官方题解的双端队列解法，即多维护一个不增序列（后一项比前一项递减或者相等），如果push进来的后一项大于前面的，则一直pop直到满足不增的性质。

### 代码

```javascript
var MaxQueue = function() {
    //  队列
    this.queue = [];
    // 辅助的双端队列，有“不增”的性质要求
    this.deque = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.deque.length ? this.deque[0] : -1;
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.queue.push(value);
    // deque中一直pop直到满足push后仍然具有不增的性质
    while (this.deque.length !== 0
            && this.deque[this.deque.length - 1] < value) {
        this.deque.pop();
    }
    this.deque.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if (!this.queue.length) {
        return -1;
    }
    const front = this.queue.shift();
    if (this.deque[0] === front) {
        this.deque.shift();
    }
    return front;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```

### 其他

我的 github [@ceynri](https://github.com/ceynri) 欢迎访问~

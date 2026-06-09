### 解题思路
左手倒右手，快乐无穷多。

### 代码

```javascript
var CQueue = function () {
    this.stack1 = [];
    this.stack2 = [];
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function (value) {
    this.stack1.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function () {
    if (!this.stack2.length) {
        if (!this.stack1.length) {
            return -1
        } else {
            while (this.stack1.length) {
                this.stack2.push(this.stack1.pop())
            }
        }
    }
    return this.stack2.pop()
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```

![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/f48ff8c7de8ebd96afe76391439767fa72cabcd83ddea65dc957787c4ebc6ca5-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

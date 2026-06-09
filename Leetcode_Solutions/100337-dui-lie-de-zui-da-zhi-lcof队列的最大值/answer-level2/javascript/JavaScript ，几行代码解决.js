### 解题思路
下面的代码非常少，也容易理解，会js的人都可以看懂。
虽然这样写毫无问题，但是我们还是不要忘了最原始的队列是什么样子的
队列：
- 一个队列包含头指针top，一个尾指针bottom，一个数据体arr[]
- 头指针一直指向待插入元素的位置（头指针指向的位置是空的，每次插入元素时先将元素插入到top的位置，然后top++）
- 尾指针一直指向最后一个插入的元素位置（也就是待删除的位置，删除元素时将bottom位置的元素删除，然后bottom++）
- 当top === bottom时代表队列是空的
- 而且这种普通队列存在空间浪费，所以出现了循环队列，这里就不再赘述了

### 代码

```javascript
var MaxQueue = function() {
    this.queue = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    if(!this.queue.length) return -1;
    return Math.max(...this.queue);
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    return this.queue.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if(!this.queue.length) return -1;
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
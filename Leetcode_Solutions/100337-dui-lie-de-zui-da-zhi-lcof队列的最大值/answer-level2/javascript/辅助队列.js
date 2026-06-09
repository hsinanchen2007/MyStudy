### 解题思路
辅助数组实现当前最大队列。

用一个 maxArray，表示当前队列中的最大队列。
- 当 array 不为空时，当前的 max_value 就是 maxArray[0]
- 当 push_back 时，从 maxArray 的末尾比较，如果 value 大于 maxArray[i]，则 maxArray 弹出末尾的元素（比 value 小的且在 value 之前入队的元素都不能成为 max_value）
- 当 pop_front 时，如果 maxArray[0] 正好等于 array[0]，弹出 maxArray[0] 


### 代码

```javascript
var MaxQueue = function() {
    this.array = new Array();
    this.maxArray = new Array();
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.array.length ? this.maxArray[0] : -1;
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.array.push(value);
    while (this.maxArray.length && this.maxArray[this.maxArray.length-1] < value) {
        this.maxArray.pop();
    }
    this.maxArray.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if (!this.array.length) return -1;
    const shiftElement = this.array.shift();
    if (shiftElement === this.maxArray[0]) {
        this.maxArray.shift();
    }
    return shiftElement;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```

### 复杂度
- 时间复杂度 O(1)
- 空间复杂度 O(N)
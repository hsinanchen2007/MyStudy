### 解题思路
此处撰写解题思路

### 代码

```javascript
var MaxQueue = function() {
    this.que = [];
    this.maxvalue = undefined;
};

/**
 * @return {number}
 * 根据最大值是否存在，返回最大值
 */
MaxQueue.prototype.max_value = function() {
    if(this.maxvalue === undefined) return -1;
    return this.maxvalue;
};

/** 
 * @param {number} value
 * @return {void}
 * 添加数据到队列，实时更新最大值，返回null
 */
MaxQueue.prototype.push_back = function(value) {
    this.que.push(value);
    if(this.maxvalue === undefined) this.maxvalue = value;
    else this.maxvalue = this.maxvalue > value ? this.maxvalue : value;
    return null;
};

/**
 * @return {number}
 * 根据队列是否为空，更新最大值，返回弹出的值
 * 如果弹出的是最大值，则需更新最大值
 */
MaxQueue.prototype.pop_front = function() {
    var res = this.que.shift();
    if(this.que.length === 0) this.maxvalue = undefined;
    else if(this.maxvalue === res) {
        this.maxvalue = this.que[0];
        this.que.forEach((item) => {
            this.maxvalue = this.maxvalue > item ? this.maxvalue : item;
        })
    }
    if(res === undefined) return -1;
    return res;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
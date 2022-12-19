### 解题思路
均摊时间复杂度, 学到了

### 代码

```javascript
var MaxQueue = function() {
    this.queue = []
    this.maxQueue = []
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    if(this.maxQueue.length){
        return this.maxQueue[0]
    }else{
        return -1
    }
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    while(this.maxQueue[this.maxQueue.length - 1] < value){
        this.maxQueue.pop()
    }
    this.maxQueue.push(value)
    this.queue.push(value)
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if(this.queue.length){
        let v = this.queue.shift()
        if(v === this.maxQueue[0]){
            this.maxQueue.shift()
        }
        return v
    }else{
        return -1
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
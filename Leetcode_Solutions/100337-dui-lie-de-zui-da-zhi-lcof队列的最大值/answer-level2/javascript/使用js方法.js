受第一天做的题  启发，在构造函数里用this.queue
但是时间复杂度貌似不能满足，但是提交通过了额
比较难想的还是最大值怎么存储吧
```
var MaxQueue = function() {
    this.queue = []
    //this.max = -1
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    //return this.max
    if(this.queue.length == 0) return -1
    var max = Math.max.apply(null , this.queue)
    return max
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.queue[this.queue.length] = value
    //this.max = Math.max(this.max , value)
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    // var result = this.queue[0]
    // this.queue.length -= 1
    // return result
    if(this.queue.length == 0) return -1
    var result = this.queue.shift()
    return result
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```

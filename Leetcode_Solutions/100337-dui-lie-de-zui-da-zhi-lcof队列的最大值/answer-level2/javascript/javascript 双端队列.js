```
var MaxQueue = function() {
    this.queue1 = [];
    this.queue2 = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.queue2[0] || -1;
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.queue1.push(value);
    let i = this.queue2.length;
    while(i - 1 >= 0 && this.queue2[i - 1] < value) i--;
    this.queue2 = (this.queue2.slice(0, i));
    this.queue2.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    const res = this.queue1.shift();
    if(res === this.queue2[0]) this.queue2.shift();
    return res || -1;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```

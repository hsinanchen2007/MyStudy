### 解题思路
借助自带的Math.max方法返回队列的最大值
借助push方法在队列末尾加入值
借助shift方法从队列首部删除元素
注意：插入和删除元素都要判断最大值有没有变化并返回最大值

### 代码

```javascript
var MaxQueue = function() {
    this.queue = [];
    this.maxValue = -1;
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    return this.maxValue;
};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    this.maxValue = Math.max(this.maxValue,value);
    this.queue.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    if(this.queue.length>0){
        var front = this.queue.shift();
         if(this.queue.length===0){
            this.maxValue = -1;
        }
        if(front === this.maxValue){
            this.maxValue = Math.max(...this.queue);
        }
       
        return front;
    }else{
        return -1;
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
### 解题思路
此处撰写解题思路

### 代码

```javascript
var MaxQueue = function() {
    this.qu=[];

};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function() {
    let qu=this.qu;
    if(qu.length===0)return -1;
    return Math.max(...qu);


};

/** 
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function(value) {
    let qu=this.qu;

    qu.push(value);

};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function() {
    let qu=this.qu;

    if(qu.length===0)return -1; 

    return qu.shift();

};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
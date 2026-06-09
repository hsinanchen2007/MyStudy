```
var MaxQueue = function() {
    this.que = []
    // 临时保存最大值
    this.maxValue = -Infinity
}
MaxQueue.prototype.max_value = function() {
    return this.que.length == 0 ? -1 : this.maxValue
}
MaxQueue.prototype.push_back = function(value) {
    this.que.push(value)
    if(value > this.maxValue) {
      this.maxValue = value
    }
}
MaxQueue.prototype.pop_front = function() {
    if(!this.que.length) {
      return -1
    }
    let temp = this.que.shift()
    if(temp === this.maxValue) {
      // 数组解构 + Math最大值函数 hhhh
      this.maxValue = Math.max(...this.que)
    }
    return temp
}
```

```js
/**
 * Initialize your data structure here.
 */
var HitCounter = function() {
    this.arr = []
};

/**
 * Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). 
 * @param {number} timestamp
 * @return {void}
 */
HitCounter.prototype.hit = function(timestamp) {
    this.arr[timestamp-1] = this.arr[timestamp-1] + 1 || 1
};

/**
 * Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). 
 * @param {number} timestamp
 * @return {number}
 */
HitCounter.prototype.getHits = function(timestamp) {
    let left = ((timestamp - 300) < 0) ? 0 : (timestamp - 300)
    let right = timestamp
    let arr = this.arr.slice(left,right)
    return arr.length ? arr.reduce((acc, cur) => acc+cur) : 0
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */
```
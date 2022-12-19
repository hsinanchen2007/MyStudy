```
var MyCalendar = function() {
    this.cal = []
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function(start, end) {
    let left = 0
    let right = this.cal.length
    while(left < right) {
        const mid = Math.floor((left + right) / 2)
        const [e1, e2] = this.cal[mid]
        if(start >= e2) {
            left = mid + 1
        } else if(end <= e1) {
            right = mid
        } else return false
    }
    this.cal.splice(left, 0, [start, end])
    return true
};

/** 
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */
```

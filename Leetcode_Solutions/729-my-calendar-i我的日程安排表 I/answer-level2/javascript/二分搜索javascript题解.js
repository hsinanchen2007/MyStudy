### 解题思路

大家好，我是 17

二分法重要是要熟练，虽然原理简单，但是写起每次写对不容易，边界问题不好处理。
所以需要记一套模板，代码中用的就是我用的模板，二分中我只做搜索，不处理任何别的逻辑。

```javascript
if (this.data[mid][0] >= end) {
      high = mid
}
```

因为是左半右开（左值大于等于，右值小于），上面的限定 一定会把low限定到 插入位置。

### 代码

```javascript
var MyCalendar = function () {
  this.data = []
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function (start, end) {
  let low = 0, high = this.data.length
  while (low < high) {
    let mid = low + ((high - low) >> 1)
    if (this.data[mid][0] >= end) {
      high = mid
    }
    else {
      low = mid + 1
    }
  }

  if (low - 1 < 0||start >= this.data[low - 1][1]) {
    this.data.splice(low, 0, [start, end])
    
    return true
  }

  else {
      return false
  }
}
/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */
```
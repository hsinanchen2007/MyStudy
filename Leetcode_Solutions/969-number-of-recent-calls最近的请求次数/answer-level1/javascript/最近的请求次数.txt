```
var RecentCounter = function () {
  this.pings = []
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
  let count = 0
  let len = this.pings.length
  if (len > 0 && t < this.pings[len - 1]) {
    return
  }
  this.pings.push(t)
  len++
  for (let i = len - 1; i >= 0; i--) {
    if (t - this.pings[i] <= 3000) {
      count++
    } else {
      break
    }
  }
  return count
};
```

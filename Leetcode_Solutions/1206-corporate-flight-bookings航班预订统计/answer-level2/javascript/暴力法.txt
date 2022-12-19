### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
    // 初始化
    let arr = []
    for (let i = 0; i< n; i++){
      arr[i] = 0
    }
    bookings.forEach((item)=>{
      add(item[0], item[1], item[2])
    })
    return arr

    function add (start, end, t) {
      for (let i = start; i <= end; i++) {
          arr[i-1] += t
      }
      return
    }
};
```
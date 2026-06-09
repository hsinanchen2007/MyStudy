### 解题思路
我这就是笨办法，将每一个行班对应的预定数强制分解开。按照题目数组得到一下图，看图写的的代码
- 航班n        1  2  3  4  5
- bookings[0] 10 10
- bookings[1]    20 20
- bookings[2]    25 25 25 25
- 总计         10 55 45 25 25

### 代码

```javascript
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
    let allBook = new Array(n).fill(0);
    for(let i = 0; i < bookings.length; i++) {
        let mapIndex = bookings[i][1] - bookings[i][0];
        for(let j = 0; j < mapIndex + 1 ;j++ ) {
            allBook[bookings[i][0] + j - 1] += bookings[i][2]
        }
    }
    return allBook
};
```
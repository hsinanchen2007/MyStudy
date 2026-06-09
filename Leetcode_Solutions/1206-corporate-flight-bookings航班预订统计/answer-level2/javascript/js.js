### 解题思路
js

### 代码

```javascript
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
    var result = new Array(n)
    for(let a = 0; a < n; a++){
        result[a] = 0
    }
    for(let i = 0; i < bookings.length; i++){
        for(let m = bookings[i][0]; m <= bookings[i][1]; m++){
            result[m - 1] = result[m - 1] + bookings[i][2]
        }
    }
    
    return result
};



```
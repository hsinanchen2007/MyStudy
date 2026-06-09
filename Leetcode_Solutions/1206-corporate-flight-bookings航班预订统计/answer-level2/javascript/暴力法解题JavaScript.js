### 解题思路
bookings数组循环下，在每一段[i,j,k]中i-j的区间进行循环，只要在此区间下，对应的航班上就加上K个。

### 代码

```javascript
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
   // console.log(n);
    var answer = Array(n).fill(0);
    for(let i = 0; i < bookings.length; i++){
        for(let j = bookings[i][0]; j <= bookings[i][1]; j++){
           let w = bookings[i][2];
           //let e;
           if(answer[j-1] == 0){
                answer[j-1] = w;
           }
           else{
               answer[j-1] += w;
           }
           //console.log(e);
        }
    }
    return answer;
};
```
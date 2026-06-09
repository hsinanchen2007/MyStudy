```
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
    const ans = new Array(n + 1).fill(0)
    for(let i=0;i<bookings.length;i++){
        ans[bookings[i][0]] += bookings[i][2]
        if(bookings[i][1] < n) {
            ans[bookings[i][1] + 1] -= bookings[i][2]
        }
    }
    ans.shift()
    for(let i=1;i<ans.length;i++){
        ans[i] +=  ans[i - 1]
    }
    return ans
};
```

废话少说 上代码
```
func corpFlightBookings(bookings [][]int, n int) []int {
    ret := make([]int, n+2)
    for i := 0; i < len(bookings) ; i++ {
        ret[bookings[i][0]] +=  bookings[i][2]
        ret[bookings[i][1]+1] -=  bookings[i][2]
    }
    ret[0] = ret[1]
    for i := 1; i < n; i++ {
        ret[i] = ret[i-1] + ret[i+1]
        
    }
    return ret[:n]
}
```



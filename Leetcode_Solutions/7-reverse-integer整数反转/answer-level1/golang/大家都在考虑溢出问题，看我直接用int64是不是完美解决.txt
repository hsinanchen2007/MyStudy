```
func reverse(x int) int {   
    reverse:=int64(0)  
    for x != 0 {
        reverse = reverse*10 + int64(x%10)
        x = x/10
    }
    if reverse > math.MaxInt32 || reverse < math.MinInt32{
        return 0
    }
    return int(reverse)
}
```
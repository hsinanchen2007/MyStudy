```go
func reverse(x int) int {
   ret := 0
   for x != 0 {
      pop := x % 10
      x /= 10
      ret = ret*10 + pop
      if ret < math.MinInt32 || ret > math.MaxInt32 {
         return 0
      }
   }
   return ret
}
```


```golang
var m =  map[int]int{1:1,2:2}
func climbStairs(n int) int {
   if v,ok := m[n];ok {
       return v
   }
   m[n] = climbStairs(n-1) + climbStairs(n-2)
   return  m[n]
}
```
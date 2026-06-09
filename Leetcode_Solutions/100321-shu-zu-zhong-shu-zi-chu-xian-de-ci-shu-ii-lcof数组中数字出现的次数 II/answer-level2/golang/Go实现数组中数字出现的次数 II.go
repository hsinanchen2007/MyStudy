

```golang
func singleNumber(nums []int) int {
   help := make(map[int]int)
   for _,v := range nums{
       help[v]++
   }
   for _,s := range nums{
       if help[s]==1{
           return s
       }
   }
   return -1
}
```
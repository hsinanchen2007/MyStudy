自己用的两层遍历效率比较低，看了一下官方的历史最小值，自己写了一下优化的100%，这种思路值得学习。
```
func maxProfit(prices []int) int {
    if len(prices)<=1{
        return 0
    }
   hmin:=prices[0]
   max:=0
   ans:=0
   for i:=1;i<len(prices);i++{
         if hmin>prices[i]{
             hmin=prices[i]
         }else{
         ans=prices[i]-hmin
         if ans>max{
             max=ans
         }
         }
   }
   return max
}
```

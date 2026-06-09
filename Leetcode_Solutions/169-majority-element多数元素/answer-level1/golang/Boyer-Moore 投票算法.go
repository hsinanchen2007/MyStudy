### 解题思路
“Boyer-Moore 投票算法”可以分两种情况考虑：

如果候选众数c都是真正的众数maj，根据众数的定义，众数的数量要比其它数的数量和还要多，因此，如果每一个候选众数c都消除掉一个其它数（不等于c的数），那最后剩下的必定是众数。
如果候选众数c中存在非众数，同样，由于每一个候选众数c都消除掉一个其它数（!=c），可能会有真正众数maj或者除c以外的其他非众数被消掉，最后剩下的数必然还是众数，而且剩余众数数量>第一种情况剩余众数数量。
综上，最后剩下的一定是众数。
### 代码

```golang
func majorityElement(nums []int) int {
   candidate,count := 0,0
   for _,n :=range nums{
       if count == 0{
           candidate = n
       }
       if candidate == n{
           count++
       }else{
           count--
       }
   }
    return candidate
}
```
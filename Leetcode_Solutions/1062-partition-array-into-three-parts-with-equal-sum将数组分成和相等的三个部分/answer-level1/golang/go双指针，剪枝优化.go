### 解题思路
双指针法。从头到尾，从尾到头，先要算出3等分的值，再进行遍历
一个优化点是左边遍历结束如果不满足等于1/3 直接返回false

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
var sum int = 0
for _,val :=range A{
sum+=val
}
//数组和除不尽 则直接返回false
if(sum%3 != 0){
return false
}
var needSum int = sum/3
left := 0
right := len(A)-1
sum1 := 0
for{
    sum1 += A[left]
if left >= right || sum1 == needSum{
    break
}
    left++
}
//如果此时就已经不满足条件，返回false
if(sum1 != needSum){
    return false
}
sum1 = 0
for{
    sum1+= A[right]
if left >= right || sum1== needSum{
    break
}
    right--
}
//如果是 right>left的话。有可能会只分成2段
if right>left+1 {
    return true
}
return false
}
```
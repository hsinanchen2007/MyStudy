```
func maxSubArrayLen(nums []int, k int) int {
    sumDic:=make(map[int]int)
    var sum=0
    var rel = 0
    for Key,v:=range nums {
        sum+=v
        if _,ok:= sumDic[sum];!ok{
            sumDic[sum]=Key
        }
        if sum==k{
           rel=Key+1 
        }else if _, ok := sumDic[sum-k]; ok {
            rel=int(math.Max(float64(rel),float64(Key-sumDic[sum-k])))
        }
    }
    return rel
}
```

参考题解区余先声的解法
```
func isPossibleDivide(nums []int, k int) bool {
    var res arr
    res = make(arr,len(nums))
    for key,_:=range nums{
        res[key] = nums[key]
    }
    sort.Sort(res)
    if len(nums)%k!=0{
        return false
    }
    hashmap:=make(map[int]int)
    for _,val:=range nums{
        hashmap[val] = hashmap[val] + 1
    }
    needK:=len(nums)/k
    kcount:=0
    for _,val:=range res{
        if hashmap[val] == 0{
            continue
        }
        hashmap[val] = hashmap[val] - 1
        for i:=1;i<k;i++{
            if hashmap[val+i]==0{
                return false
            }
            hashmap[val+i] = hashmap[val+i] - 1
        }
        kcount = kcount + 1
        if kcount == needK{
            return true
        }
    }
    return true



}
type arr []int
func (this arr) Len()int{
    return len(this)
}
func (this arr) Less(i,j int) bool{
    if (this)[i]<(this)[j]{
        return true
    }else{
        return false
    }
}
func (this arr) Swap(i,j int){
    (this)[i],(this)[j] = (this)[j],(this)[i]
}
```

```
func containsDuplicate(nums []int) bool {
    var i int
    var mapper map[int]int
    mapper=make(map[int]int)
    for i=0;i<len(nums);i++{
        _,ok:=mapper[nums[i]]
        if ok==true{
            return true
        }
        mapper[nums[i]]++
    }
    return false
}
```

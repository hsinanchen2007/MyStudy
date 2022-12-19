```
func longestConsecutive(nums []int) int {
    var maps = make(map[int]bool)
    if len(nums)==0||len(nums)==1{
        return len(nums)
    }
    for _,v := range nums{
        maps[v] = true
    }
    var count = 1
    var max  = 1
    for i:=0;i<len(nums);i++{
        if _,ok := maps[nums[i]-1];ok{ //如果比当前数小1的数存在，说明该数不是一个连续序列的起点
            continue
        }else{
            count = 1
            v := nums[i]
            for {
                if _,ok := maps[v+1];ok{ //如果当前数+1的数存在，长度+1
                    count++
                    v++
                    if count>max{
                        max = count
                    }
                }else{
                    break
                }
            }
        }
    }
    return max
}
```

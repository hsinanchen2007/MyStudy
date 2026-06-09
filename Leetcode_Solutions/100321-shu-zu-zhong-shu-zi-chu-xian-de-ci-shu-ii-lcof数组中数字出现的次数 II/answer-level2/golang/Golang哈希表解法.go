### 代码

```golang
func singleNumber(nums []int) int {
    note:=map[int]int{}
    for _,v:=range nums{
        note[v]++
    }
    for k,v:=range note{
        if v==1{
            return k
        }
    }
    return 0
}
```
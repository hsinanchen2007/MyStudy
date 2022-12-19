### 代码

```golang
func singleNumbers(nums []int) []int {
    note:=map[int]bool{}
    for _,num:=range nums{
        if _,ok:=note[num];!ok{
            note[num]=true
        }else{
            delete(note,num)
        }
    }
    res:=[]int{}
    for k:=range note{
        res=append(res,k)
    }
    return res
}
```
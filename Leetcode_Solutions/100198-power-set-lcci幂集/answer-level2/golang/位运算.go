### 代码

```golang
func subsets(nums []int) [][]int {
    num:=1<<len(nums)
    var res [][]int
    for i:=0;i<num;i++{
        var tmp []int
        t:=0
        for j:=i;j!=0;j=j>>1{
            if j&1==1{
                tmp=append(tmp,nums[t])
            }
            t++
        }
        res=append(res,tmp)

    }
    return res
}
```
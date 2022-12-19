### 代码

```golang
func findContinuousSequence(target int) [][]int {
    res:=[][]int{}
    lo,hi:=1,2
    for hi<=target/2+1{
        sum:=(lo+hi)*(hi-lo+1)/2
        if sum==target{
            tmp:=make([]int,(hi-lo+1))
            for i:=0;i<hi-lo+1;i++{
                tmp[i]=lo+i
            }
            res=append(res,tmp)
            lo++
        }else if sum<target{
            hi++
        }else{
            lo++
        }
    }
    return res
}
```
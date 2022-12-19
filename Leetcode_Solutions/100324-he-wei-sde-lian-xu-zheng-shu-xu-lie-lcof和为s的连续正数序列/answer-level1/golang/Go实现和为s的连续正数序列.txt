

```golang
func findContinuousSequence(target int) [][]int {
    if target<3{
        return [][]int{}
    }
    res := [][]int{}
    small,big := 1,2
    curSum := big+small
    middle:= (1+target)/2
    for small<middle{
        if curSum==target{
           tmp := print(small,big)
            res = append(res,tmp)
        }
        for curSum>target&& small<middle{
            curSum-=small
            small++
            if curSum==target{
                tmp :=print(small,big)
                res = append(res,tmp)
            }
        }
        big++
        curSum+=big
    }
    return res
}
func print(a,b int)[]int{
    rs := []int{}
    for i:=a;i<=b;i++{
        rs = append(rs,i)
    }
    return rs
}
```
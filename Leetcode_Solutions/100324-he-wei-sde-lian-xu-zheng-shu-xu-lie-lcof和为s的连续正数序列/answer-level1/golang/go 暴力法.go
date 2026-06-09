```
func findContinuousSequence(target int) [][]int {
    half := target/2 +1
    ret := make([][]int, 0)
    s := make([]int, half)
    for i:=0;i<half;i++{
        s[i] = i+1
    }
    for i := 1;i<half;i++{
        sum := i
        for j:=i+1;j<half+1;j++{
            sum += j
            if sum > target {
                break
            }
            if sum == target {
                ret = append(ret, s[i-1:j])
            }
        }
    }
    return ret
}
```

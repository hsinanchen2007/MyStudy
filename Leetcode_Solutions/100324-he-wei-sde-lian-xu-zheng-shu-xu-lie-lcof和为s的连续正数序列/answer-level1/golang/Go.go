```
func findContinuousSequence(target int) [][]int {
    ret := make([][]int, 0)
    half := target / 2 + 1
    i, j := 1, 2
    sum := 3
    for j<= half{
        if sum == target {
            tmp := make([]int, j-i+1)
            s := i
            for a:=0;a<j-i+1;a++{
                tmp[a] = s
                s++
            }
            ret = append(ret, tmp)
            sum -= i
            i++
            j++
            sum += j
        }else if sum > target {
            sum -= i
            i++
        }else{
            j++
            sum += j
        }
    }
    return ret
}
```

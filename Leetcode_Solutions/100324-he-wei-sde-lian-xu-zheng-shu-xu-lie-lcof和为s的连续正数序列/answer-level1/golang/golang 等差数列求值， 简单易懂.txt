根据等差数列求值:
i + ... + j = (i + j) * (j - i + 1) / 2
遍历 1～target即可 （其实只要遍历 1 ～ target/2）
```
func findContinuousSequence(target int) [][]int {
    ret := [][]int{}
    for i := 1; i < target; i++ {
        t := []int{i}
        for j := i + 1; (i + j) * (j - i + 1) / 2 <= target; j++ {
            t = append(t, j)
            if (i + j) * (j - i + 1) / 2 == target {
                ret = append(ret, t)
            }
        }
    }
    return ret
}
```

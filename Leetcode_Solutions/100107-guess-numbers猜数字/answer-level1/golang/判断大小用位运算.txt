# 时间是快了 空间还能优化么？？？
```
func game(guess []int, answer []int) int {
    var times int
    for i := 0; i < len(guess); i++ {
        if ((answer[i] ^ guess[i]) == 0) {
            times++
        }
    }
    return times
}
```

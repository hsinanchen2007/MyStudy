只要比较guess[i] == answer[i]是否相等。。。
```
func game(guess []int, answer []int) int {
    ret := 0
    for i := 0; i < len(guess); i++ {
        if guess[i] == answer[i] {
            ret++
        }
    }
    return ret
}
```

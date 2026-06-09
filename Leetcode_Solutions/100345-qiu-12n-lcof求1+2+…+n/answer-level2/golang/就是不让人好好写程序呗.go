看了评论区大神的各种奇技淫巧，我算是明白了，这题就是不想让人好好写程序呗
```golang
func sumNums(n int) int {
    slot := make(chan struct{}, n)
    sum := 0
loop:
    sum += n
    n -= 1
    select {
    case slot <- struct{}{}:
    default:
        return sum
    }
    goto loop
}
```
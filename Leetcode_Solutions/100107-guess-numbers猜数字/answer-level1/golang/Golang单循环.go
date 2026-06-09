解答思路：两个数组长度一样，golang：for-range单循环实现
```
func game(guess []int, answer []int) int {
    count := 0
    for k, v := range guess {
        if v == answer[k] {
            count++
        }
    }
    return count
}
```

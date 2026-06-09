```
// size == 0 全是小写
// size == len(chs) 全是大写
// size == 1 && fistUppercase 只有一个大写，且是第一个字母
func detectCapitalUse(word string) bool {
    fistUppercase := false
    size := 0
    chs := []rune(word)
    for i := 0; i < len(chs); i++ {
        if (65 <= chs[i]) && (chs[i] <= 90) { // 大写字母
            size++ 
            if i == 0 {fistUppercase = true}// 第一个字母大写
        }
    }
    return size == 0 || size == len(chs) || (size == 1 && fistUppercase)
}
```
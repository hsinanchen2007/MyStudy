### 解题思路
使用map，记录每个字符出现的次数，如果次数大于1,则表示有重复的字符。

### 代码

```golang
func isUnique(astr string) bool {
    md := make(map[rune]int)
    for _, v := range astr {
        md[v]++
        if md[v] > 1 {
            return false
        }
    }
    return true
}
```
### 解题思路
时间复杂度O(n) n为字符串长度。

遍历整个字符串，取每个字符串的字符，挨个放到一个哈希表中，每次取之前，先从哈希表中判断有没有，但凡是有，则证明是重复了，就返回错误

### 代码

```golang
func isUnique(astr string) bool {
    sMap := make(map[rune]rune, 0)
    runeArray := []rune(astr)

    for _, e := range runeArray{
        if _, ok := sMap[e]; ok {
            return false
        }else {
            sMap[e]=e
        }
    }
    return true
}
```
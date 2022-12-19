### 解题思路
此处撰写解题思路

### 代码

```golang
func canPermutePalindrome(s string) bool {
    if len(s) == 0 {
        return false
    }
    cntOdd := 0
    cntMap := make(map[rune]int, 0)
    for _, sn := range s {
        cntMap[sn] ++
    }
    for _, n := range cntMap {
        if n & 1 != 0 {
            cntOdd ++
        }
    }
    return cntOdd <= 1
}
```
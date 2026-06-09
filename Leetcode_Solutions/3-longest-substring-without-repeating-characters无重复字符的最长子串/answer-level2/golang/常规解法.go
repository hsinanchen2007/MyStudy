### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    result := 0
    for i := 0; i < len(s); i++ {
        max := 0
        tempMap := map[rune]bool{}
        counter := 0
        for j := i; j < len(s); j++ {
            if tempMap[rune(s[j])] {
                break
            } else {
                counter++
                tempMap[rune(s[j])] = true
            }
            max = counter
        }
        if max > result {
            result = max
        }
    }
    return result
}
```
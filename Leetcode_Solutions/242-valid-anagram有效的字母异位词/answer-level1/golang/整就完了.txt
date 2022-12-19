### 解题思路
此处撰写解题思路

利用map
### 代码

```golang
func isAnagram(s string, t string) bool {

    if len(s) != len(t) {
        return false
    }

    strMap := make(map[string]int)

    for i := 0; i < len(s); i++ {
        strMap[string(s[i])]++
    }

    for j := 0; j < len(t); j++ {
        strMap[string(t[j])]--
    }

    for _, v := range strMap {
        if v != 0 {
            return false
        }
    }
    return true
}
```
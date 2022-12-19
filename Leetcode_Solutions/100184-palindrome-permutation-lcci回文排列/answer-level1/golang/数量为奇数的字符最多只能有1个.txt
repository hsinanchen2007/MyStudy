### 解题思路
数量为奇数的字符最多只能有1个

### 代码

```golang
func canPermutePalindrome(s string) bool {
    // 数量为奇数的字符最多只能有1个
    hashMap := make(map[rune]uint)
    for _, char := range s {
        _, ok := hashMap[char]
        if !ok {
            hashMap[char] = 1
        }else{
            hashMap[char]++
        }
    }

    var hasOld bool = false
    for _, v := range hashMap {
        if v%2 != 0 {
            if hasOld {
                return false
            }else{
                hasOld = true
            }
        }
    }
    return true
}
```
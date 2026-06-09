左右遍历双指针字符串，看是否为非字符字符，如果是的话直接对空字符进行移动。
如果不是，则看是否相等。
如果不相等，看是否为大小写字符，如果不是大小写字符，返回false。遍历完成返回true

```
func isPalindrome(s string) bool {
    i, j := 0, len(s) - 1
    for i < j {
        if !isValidAlphanumeric(s[i]) {
            i++
            continue
        } 

        if !isValidAlphanumeric(s[j]) {
            j--
            continue
        }

        if s[i] == s[j] || isUpperOrLower(s[i], s[j]) {
            i++
            j--
        }else {
            return false
        }
    }
    return true
}

func isValidAlphanumeric(s byte) bool {
    return (s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')
}

func isUpperOrLower(a, b byte) bool {
    return a - b == 32 || b - a == 32 && !(a >= '0' && a <= '9') && !((b >= '0' && b <= '9'))
}
```
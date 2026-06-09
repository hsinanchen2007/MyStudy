### 解题思路
...

### 代码

```golang
func shortestPalindrome(s string) string {
    lenS := len(s)
    recv := reverseString(s)
    i := 0
    for i=0;i<lenS;i++{
        if recv[i:lenS] == s[0:lenS-i] {
            break
        }
    }
    return recv[0:i] + s
}


// 反转字符串
func reverseString(s string) string {
    runes := []rune(s)
    for from, to := 0, len(runes)-1; from < to; from, to = from+1, to-1 {
        runes[from], runes[to] = runes[to], runes[from]
    }
    return string(runes)
}
```
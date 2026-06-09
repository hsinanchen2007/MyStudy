
func longestPalindrome(s string) string {
    length := len(s)
    if length < 2 {
        return s
    }
    left := 0
    right := 0
    maxLen := 0
    len := 1
    start := 0
    for i := 0 ; i < length ; i++ {
        left = i - 1
        right = i + 1
        for left >= 0 && s[left] ==  s[i]{
            left--
            len++
        }
        for right < length && s[right] == s[i]{
            right++
            len++
        }
        for left >= 0 && right < length && s[right] == s[left]{
            right++
            left--
            len += 2
        }
        if len > maxLen {
            maxLen = len
            start = left + 1
        }
        len = 1
    }
    return s[start:start+maxLen]
}
```golang []
// 暴力求解;由原串生产出所有子串的情况，判断是否为回文。然后得到最大值
func longestPalindrome(s string) string {
    max := []byte{}
    l := len(s)
    bs := []byte(s)
    for start:=0;start<l;start++ { // 外层循环为子串的开始位置
        for end :=start;end<l;end++ { // 内层循环为子串的结束位置
            substr := bs[start:end+1]
            if isPalindrome(substr) && len(max) < len(substr) {
                max = substr
            }
        }
    }
    return string(max)
    
}

// 判断是否为回文字符串
func isPalindrome(s []byte) bool{
    i,j:=0,len(s)-1
    for i<j{
        if s[i] != s[j] {
            return false
        }
        j--
        i++
    }
    return true
}
```

```golang
func reverseLeftWords(s string, n int) string {
    if s == "" {
        return s
    }
    str := []rune(s)
    reverse(str,0,n-1)
    reverse(str,n,len(str)-1)
    reverse(str,0,len(str)-1)
    return string(str)
}

func reverse(str []rune,left,right int){
    for left<right{
        str[left],str[right] = str[right],str[left]
        left++
        right--
    }
}
```
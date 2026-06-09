```golang []
func lengthOfLongestSubstring(s string) int {
    flag := [256]int{}
    beg := 0
    max := 0
    for i := 0; i < len(s); i++ {
        if flag[s[i]] > 0 && flag[s[i]] > beg {
            beg = flag[s[i]]   
        } 
        flag[s[i]] = i+1
        max = maxnum(max, i - beg + 1)
    }
    return max
}

func maxnum(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

4ms，怎样再优化？
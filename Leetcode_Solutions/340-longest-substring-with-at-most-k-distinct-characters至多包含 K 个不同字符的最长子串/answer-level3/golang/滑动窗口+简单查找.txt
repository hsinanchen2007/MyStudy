```
func lengthOfLongestSubstringKDistinct(s string, k int) int {
    n := len(s)
    if n*k == 0 { return 0 }
    ans := 0
    mp := make(map[byte]int)
    
    for left, right := 0, 0; right < n; right++ {
        if len(mp) < k+1 {
            mp[s[right]] = right
        }
        // Optimazation: 有序字典
        if len(mp) == k+1 {
            for left != mp[s[left]] {
                left++
            }
            delete(mp, s[left])
            // left point to the next
            left += 1
        }
        ans = max(ans, right-left+1)
    }
    return ans
}

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}
```

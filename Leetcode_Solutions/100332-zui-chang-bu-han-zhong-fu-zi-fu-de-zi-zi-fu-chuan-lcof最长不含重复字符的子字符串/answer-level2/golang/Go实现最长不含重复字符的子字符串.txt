### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    if len(s)==0{
        return 0
    }
    res := 0
    freq := make([]int,256)
    l,r := 0,-1
    for l < len(s){
        if r+1<len(s) && freq[s[r+1]] == 0{
            r++
            freq[s[r]]++
        }else{
            freq[s[l]]--
            l++
        }
        res = int(math.Max(float64(res),float64(r-l+1)))
    }
    return res
}
```
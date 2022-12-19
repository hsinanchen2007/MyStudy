### 解题思路
俩种思路
第一种思路： 找出字符串的所有子字符串，以此验证是否为回文字符串，找出最大的。时间复杂度O(n^3)
第二种思路： 回文字符串从中点向左右俩边扩展，左右俩边一定是相同的。遍历一遍数组，找出所有的可能成为回文串中轴的组合，查看最大的字符串。时间复杂度O(n^2)

### 代码

第一种思路：
```golang
func longestPalindrome(s string) string {
    // 第一种思路：找出每一个子字符串，判断其是不是回文字符串
    length := len(s)
    if length == 0 {
        return ""
    }
    max := 0
    maxl := 0
    maxr := 0
    for i:=0;i<length;i++ {
        for j:=i+1; j<length; j++ {
            ret := isPalindromic(s, i, j)
            if ret {
                if max < (j-i+1) {
                    max = j - i + 1
                    maxl = i
                    maxr = j
                }
            }
        }
    }
    maxString := ""
    for i:=maxl; i<=maxr; i++ {
        maxString += string(s[i])
    }
    return maxString

    
}

func isPalindromic(s string, l, r int) bool {
    for l < r {
        if s[l] == s[r] {
            l++
            r--
        }else{
            return false
        }
       
    }
    return true
}
```

```
第二种思路：
// 第二种思路：遍历字符串，找出以每个字符为中心的回文字符串有多长，选最长的返回
func longestPalindrome(s string) string {
    length := len(s)
    getLen := func(i, j int) int {
        // 以s[i]s[j]为中心的最长回文字符串
        for i>=0 && j<length {
            if s[i] == s[j] {
                i--
                j++
            }else{
                return j - i - 1
            }
        }
        return j - i - 1
    }
    max := 0
    maxStart := 0
    for i:=0;i<length;i++ {
        if Max(getLen(i, i+1), getLen(i, i)) > max {
            max = Max(getLen(i, i+1), getLen(i, i))
            maxStart = i - (max-1)/2
        }
    }
    maxString := ""
    for i:=maxStart; i<maxStart+max; i++ {
        maxString += string(s[i])
    }
    return maxString
}

func Max(i, j int) int {
    if i >= j {
        return i 
    }else{
        return j
    }
}
```

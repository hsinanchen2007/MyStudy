思路：
- 首先想到的就是逐个对比。即首先将第一个元素作为最长公共前缀，从第二个元素开始按位对比，直到有不相等的或 更短的那个元素对比完为止

代码：

```go
func longestCommonPrefix(strs []string) string {
    if len(strs) ==0 {
        return ""
    }
    var (
        minPrefix = strs[0]
        minLen = len(strs[0])
    )
    
    for i := 1; i < len(strs); i++ {
        cur := strs[i]
        if len(cur) < minLen {
            minLen = len(cur) // 取更短的元素长度作为遍历次数
        }
        
        for j := 0; j < minLen; j++ {
            if cur[j] != minPrefix[j] { // 相同位置的元素不相同
                minPrefix = minPrefix[:j]
                minLen = len(minPrefix)
                break
            }
            
            if j == minLen -1 { // 遍历到更短元素的最后一位
                minPrefix = minPrefix[:minLen]
            }
        }
        
        if minLen == 0 {
            return ""
        }
    }
    
    return minPrefix
    
}
```
> 还有比较大的优化空间，希望大佬们多多指点。🙏
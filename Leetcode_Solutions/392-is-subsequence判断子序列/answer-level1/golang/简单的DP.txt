### 解题思路
此处撰写解题思路

### 代码

```golang
func isSubsequence(s string, t string) bool {
    // 找到s的每个字符在t中出现的最小位置，更新位置，后面的字符不能早于这个值
    ls := len(s)
    lt := len(t)
    if ls > lt {
        return false
    }

    dp := -1
    for i := 0; i < ls; i++ {
        found := false
        for j := dp + 1; j < lt; j++ {
            if s[i] == t[j] {
                dp = j
                found = true
                break
            }
        }
        if !found {
            return false
        }
    }

    return true
}
```
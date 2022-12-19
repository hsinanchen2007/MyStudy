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

    // 双指针更简单
    i := 0
    j := 0
    for i < ls && j < lt {
        if s[i] == t[j] {
            i++
            j++
        } else {
            j++
        }
    }
    return i == ls
}
```
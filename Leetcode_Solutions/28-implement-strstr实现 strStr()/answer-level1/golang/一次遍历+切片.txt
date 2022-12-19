执行用时 : 0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 : 2.3 MB, 在所有 Go 提交中击败了63.27%的用户
一次遍历，遇到needle的首个字符则开始切片进行比较，如果相同则输出索引，否则继续遍历。

```
func strStr(haystack string, needle string) int {
    l1 := len(haystack)
    l2 := len(needle)
    if l2 == 0 {
        return 0
    }
    for i := 0; i <= l1 - l2; i++ {
        if haystack[i] == needle[0] {
            if haystack[i:i+l2] == needle {
                return i
            }
        }
    }
    return -1
}
```

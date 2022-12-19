### 解题思路

双指针


### 参考代码

```
func isSubsequence(s string, t string) bool {
    left :=0
    tlen := len(t)
    slen := len(s)
    if slen == 0 {
        return true
    }
    if slen > tlen {
       return false
    }
    for i:=0;i<tlen;i++ {
        if s[left] == t[i] {
            left++
        }
        if left == slen {
            return true
        }
    }
    return false
}
```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**



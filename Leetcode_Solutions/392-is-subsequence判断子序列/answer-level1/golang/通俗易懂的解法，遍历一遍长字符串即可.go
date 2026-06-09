![image.png](https://pic.leetcode-cn.com/080fdd671efa733273496dc2f1ad6518a44dbb7caa0250c5cb09435983b36fb2-image.png)

```
func isSubsequence(s string, t string) bool {
    var j int = 0
    for i:=0; i<len(t); i++{
        if j < len(s) && s[j] == t[i]{
            j++
        }
    }
    if j == len(s) {
        return true
    }else{
        return false
    }
}
```
遍历t字符串就好了，然后用一个额外的变量j记录s已经匹配过的位置；
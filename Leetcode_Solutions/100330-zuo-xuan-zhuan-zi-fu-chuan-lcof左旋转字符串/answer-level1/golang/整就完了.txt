### 解题思路
此处撰写解题思路

### 代码

```golang
func reverseLeftWords(s string, n int) string {

    var res1 string
    var res2 string

    for fast := n; fast < len(s); fast++ {
        res1 += string(s[fast])
    }
    for i := 0; i < n ; i++{
        res2 += string(s[i])
    }

    return res1+res2

}
```
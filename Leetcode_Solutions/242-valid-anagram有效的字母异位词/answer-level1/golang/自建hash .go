### 解题思路
通过一个数组自建hash然后判断数目
> [了解更多](https://github.com/googege/GOFamily)

### 代码

```golang
func isAnagram(s string, t string) bool {
    ma := [26]int{}
    for _,v := range s {
        ma[v-'a']++
    }
    for _,v := range t {
        ma[v-'a']--
    }
    for _,v := range ma {
        if v != 0 {
            return false
        }
    }
    return true
}
```
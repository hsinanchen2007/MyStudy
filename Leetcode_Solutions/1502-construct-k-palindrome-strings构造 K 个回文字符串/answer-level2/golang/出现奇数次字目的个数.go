### 解题思路
出现奇数次字母的个数决定能组成多少个回文串。
- s可以构成k个非空回文串当且仅当c <= k <= len(s)，其中c为出现奇数次不同字母的个数。

### 代码

```golang
func canConstruct(s string, k int) bool {
    table := make([]int, 26)
    for _, value := range s {
        table[value-'a']++
    }
    res := 0
    for i := 0; i < 26; i++{
        if table[i]%2 == 1 {
            res ++
        }
    }
    return res <= k && k <= len(s)
}
```
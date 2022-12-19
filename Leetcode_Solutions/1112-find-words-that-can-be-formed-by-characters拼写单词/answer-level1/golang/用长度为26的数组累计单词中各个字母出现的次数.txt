### 解题思路
此处撰写解题思路

### 代码

```golang
func countCharacters(words []string, chars string) int {
    cnt := [26]int{}
    for i := 0; i < len(chars); i++ {
        cnt[int(chars[i] - 'a')]++
    }

    rlt := 0
    for i := 0; i < len(words); i++ {
        temp := [26]int{}
        for j := 0; j < len(words[i]); j++ {
            temp[int(words[i][j] - 'a')]++
        }
        contain := true
        for k := 0; k < 26; k++ {
            if cnt[k] < temp[k] {
                contain = false
                break
            }
        }
        if contain {
            rlt += len(words[i])
        }
    }
    return rlt
}
```
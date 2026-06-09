### 解题思路
此处撰写解题思路

### 代码

```golang
func countCharacters(words []string, chars string) int {
    count := 0
    for i:=0;i<len(words);i++ {
        if len(words[i]) > len(chars) {
            continue
        }
        flag := true
        cmap := attach(chars)
        for j:=0;j<len(words[i]);j++{
            if _,ok := cmap[words[i][j]];ok && cmap[words[i][j]] > 0{
                cmap[words[i][j]]--
            } else {
                flag = false
                break
            }
        }
        if flag {
            count += len(words[i])
        }
    }
    return count
}

func attach(chars string) map[byte]int {
    b := make(map[byte]int)
    for i:=0;i<len(chars);i++ {
        if _,ok := b[chars[i]];ok {
            b[chars[i]]++
        } else {
            b[chars[i]] = 1
        }
    }
    return b
}
```
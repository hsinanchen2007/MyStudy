### 解题思路
大体思路就是先找出所有big中各个字母的下标 然后对smalls进行遍历 根据下标在map中进行切片比较 如果有 则加入 想不到这方法也能100%...

### 代码

```golang
func multiSearch(big string, smalls []string) (ret [][]int) {
    if smalls == nil {
        return
    } else if smalls[0] == "" {
        ret = append(ret, []int{})
        return
    }
    m := map[byte][]int{}
    for i := range big {
        if sl, ok := m[big[i]]; ok {
            m[big[i]] = append(sl, i)
        } else {
            m[big[i]] = []int{i}
        }
    }
    for idx, word := range smalls {
        letter := word[0]
        ret = append(ret, []int{})
        if sl, ok := m[letter]; ok {
            for _, i := range sl {
                if i+len(word) <= len(big) && big[i:i+len(word)] == word {
                    ret[idx] = append(ret[idx], i)
                }
            }
        }
    }
    return
}
```
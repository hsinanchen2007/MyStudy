### 解题思路
使用map

### 代码

```golang
func countCharacters(words []string, chars string) int {
  var res int
  flag := true
  for i := range words{
    m := make(map[byte]int)
    for c := range chars { // 把字母表存入map
      m[chars[c]]++
    }
    for j := range words[i] {
      if m[words[i][j]]<=0 { // 字母表中的该字符数量小于等于0
        flag = false // 标记不能拼出该单词
        break // 跳出循环
      }
      m[words[i][j]]-- // 字母表中的该字符数量减一
    }
    if flag {
      res+=len(words[i])
    }
    flag = true
  }
  return res
}
```
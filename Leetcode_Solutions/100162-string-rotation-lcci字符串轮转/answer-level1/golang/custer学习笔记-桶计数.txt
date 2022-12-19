### 解题思路
桶计数，记录每个字符出现的次数

### 代码

```golang
func isFlipedString(s1 string, s2 string) bool {
  var m = make([]int, 256)
  for _, c := range s1 {
    m[c-'0']++
  }
  for _, c:= range s2 {
    m[c-'0']--
  }
  for _, n := range m {
    if n != 0 {
      return false
    }
  }
  return true
}
```
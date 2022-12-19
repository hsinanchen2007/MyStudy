### 解题思路
map的使用

### 代码

```golang
func firstUniqChar(s string) byte {
  // 定义一个map存储字符对应的出现次数和出现下标
  m := make(map[byte]*Pair) 
  for i := range s {
    v,ok:=m[s[i]] 
    if !ok { // 如果在map中不存在
      m[s[i]] = NewPair(i, 1) // 则新建
    }else{
      v.Value++ // 否则出现次数+1
    }
  }
  minIndex := len(s) // 最早出现一次的字符下标
  for _, v := range m { // 遍历map
    if v.Value == 1 && v.Index < minIndex {
      minIndex = v.Index // 更新最早出现一次的字符下标
    } 
  }
  if minIndex == len(s){ // 如果没有找到
    return ' ' // 返回空字符
  }
  return s[minIndex] // 否则返回该字符
}
type Pair struct {
  Index int // 出现下标
  Value int // 出现的次数
}

func NewPair(index, value int) *Pair {
  return &Pair{index, value}
}
```
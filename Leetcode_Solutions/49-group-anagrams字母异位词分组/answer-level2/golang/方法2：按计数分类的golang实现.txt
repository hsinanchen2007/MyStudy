golang中数组是可比较类型，可直接用作映射的key。
代码实现：
1. 计算每个单词的key
2. 将具有相同的key放入同一个数组中。

```golang
func groupAnagrams(strs []string) [][]string {
  m := make(map[[26]int][]string)
  for _, str := range strs {
    k := strArray(str)
    s, ok := m[k]
    if !ok {
      s := make([]string, 0)
    }
    s = append(s, str)
    m[k] = s
  }
  res := make([][]string, 0, len(m))
  for _, v := range m {
    res = append(res, v)
  }
  return res
}
// 用作计算每个单词的Key
func strArray(s string) [26]int {
  res := [26]int{}
  for _, v := range s {
    res[v - 'a']++
  }
  return res
}
```

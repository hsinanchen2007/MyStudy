### 解题思路
[全排列的方法](https://leetcode-cn.com/problems/permutations-ii/solution/custerxue-xi-bi-ji-ji-shu-by-custergo/)

### 代码

```golang
func permutation(s string) []string {
  var res []string
  helper([]byte(s), 0, &res)
  return res
}

func helper(s []byte, start int, res *[]string) {
  if start == len(s) {
    *res = append(*res, string(s))
  }
  m := make(map[byte]int)
  for i := start;i<len(s);i++{
    if _, ok:=m[s[i]];ok{
      continue
    }
    s[i],s[start] = s[start], s[i]
    helper(s, start+1, res)
    s[i],s[start] = s[start], s[i]
    m[s[i]] = 1
  }
}
```
### 解题思路
  * 读懂题目很重要，特别是值只有0，1两种结果，表示属于A或B

### 代码

```golang
func maxDepthAfterSplit(seq string) []int {
  var res []int
  level := 0
  for _,v := range seq{
    if v == '('{
      level++
      res = append(res, level%2)
    }else if v == ')'{
      res = append(res,level%2)
      level--
    }
  }
  return res
}
```
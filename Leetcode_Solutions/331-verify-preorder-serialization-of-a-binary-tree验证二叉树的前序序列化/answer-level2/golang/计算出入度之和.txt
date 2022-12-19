### 解题思路
出入度问题, 二叉树出入度为0

### 代码

```golang
func isValidSerialization(preorder string) bool {
  list := strings.Split(preorder, ",")
  count := 1
  for _,v := range list {
    if count == 0 {
      return false
    }
    if string(v) == "#" {
      count -= 1
    } else {
      count += 1
    }
  }
  
  return count == 0
}
```
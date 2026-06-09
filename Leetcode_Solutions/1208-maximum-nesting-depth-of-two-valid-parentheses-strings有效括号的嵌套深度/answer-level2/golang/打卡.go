### 解题思路
此处撰写解题思路

### 代码

```golang
func maxDepthAfterSplit(seq string) []int {
    res := make([]int, 0)
    depth := 0
    for _, b := range seq {
        if b == '(' {
            depth++
            res = append(res,depth % 2)
        } else {
            res = append(res,depth % 2)
            depth--
        }
    }
    return res
}
```
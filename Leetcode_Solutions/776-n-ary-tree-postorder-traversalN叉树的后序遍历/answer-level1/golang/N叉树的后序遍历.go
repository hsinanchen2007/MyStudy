### 解题思路
递归遍历即可

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
    var ret []int
    if root == nil {
        return ret
    }
    for _, v := range root.Children {
        ret = append(ret, postorder(v)...)
    }
    ret = append(ret, root.Val)
    return ret
}
```
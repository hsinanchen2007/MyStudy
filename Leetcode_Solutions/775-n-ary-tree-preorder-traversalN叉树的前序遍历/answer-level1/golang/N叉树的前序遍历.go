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

func preorder(root *Node) []int {
    if root == nil {
        return []int{}
    }
    var ret []int
    ret = append(ret, root.Val)
    for _, v := range root.Children {
        ret = append(ret, preorder(v)...)
    }
    return ret
}
```
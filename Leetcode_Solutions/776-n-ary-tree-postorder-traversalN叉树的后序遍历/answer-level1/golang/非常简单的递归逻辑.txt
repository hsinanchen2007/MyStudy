### 解题思路
所谓后续遍历，就先访问子节点，最后访问本节点

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
    var f func(head *Node)
    ret := make([]int, 0)
    f = func(head *Node) {
         if head != nil {
            for _, e := range head.Children {
                  f(e)          
            }
            ret = append(ret, head.Val)
        }
    }
    f(root)
    return ret 
}
```
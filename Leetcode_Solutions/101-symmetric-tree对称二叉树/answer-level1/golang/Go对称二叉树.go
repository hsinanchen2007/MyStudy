### 解题思路
go里面数据结构支持弱写起来还是比较费劲

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    var list = make([]*TreeNode,0)
    list = append(list,root)
    list = append(list,root)
    for len(list)!=0 {
        t1 := list[len(list)-1:][0]
        t2 := list[len(list)-2:len(list)-1][0]
        list = list[:len(list)-2]
        if (t1 == nil && t2 == nil) {
            continue
        }
        if (t1 == nil || t2 == nil) {
            return false
        }
        if (t1.Val != t2.Val) {
            return false
        }
        list = append(list,t1.Left)
        list = append(list,t2.Right)
        list = append(list,t1.Right)
        list = append(list,t2.Left)
    }
    return true;
}
```
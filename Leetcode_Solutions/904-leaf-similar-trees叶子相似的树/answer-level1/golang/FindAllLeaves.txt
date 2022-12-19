### 解题思路
此处撰写解题思路

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
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    l1,l2 := []int{},[]int{}
    leaves(root1,&l1)
    leaves(root2,&l2)
    if len(l1) != len(l2){
        return false
    }
    for idx := range l1{
        if l1[idx] != l2[idx]{
            return false
        }
    }
    return true
}

func leaves(r *TreeNode,ans *[]int){
    if r == nil {
        return
    }
    if r.Left == nil  && r.Right == nil {
        *ans = append(*ans,r.Val)
    }
    leaves(r.Left,ans)
    leaves(r.Right,ans)
}
```
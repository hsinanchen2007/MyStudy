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
func increasingBST(root *TreeNode) *TreeNode {
    list := []int{}
    inOrder(root,&list)
    ans := new(TreeNode)
    pre := ans
    for _,v :=range list{
        one := new(TreeNode)
        one.Val = v
        pre.Right = one
        pre = one
    }
    return ans.Right
}

func inOrder(root *TreeNode,list *[]int){
    if root == nil {
        return 
    }
    inOrder(root.Left,list)
    *list = append(*list,root.Val)
    inOrder(root.Right,list)
}
```
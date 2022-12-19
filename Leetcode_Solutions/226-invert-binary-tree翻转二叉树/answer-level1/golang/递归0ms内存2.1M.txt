### 解题思路
此处撰写解题思路
我相信大家一眼都能看出来  想要根节点翻转就需要下面两个子节点各自翻转后 然后子节点对调
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
func invertTree(root *TreeNode) *TreeNode {
    if root==nil{
        return nil
    }
	left:=root.Left
	right:=root.Right
	if left==nil&&right==nil{
		return root
	}
	l1:=invertTree(left)//左子节点翻转
	r1:=invertTree(right)//右子节点翻转
	root.Right=l1
	root.Left=r1
	return root
}
```
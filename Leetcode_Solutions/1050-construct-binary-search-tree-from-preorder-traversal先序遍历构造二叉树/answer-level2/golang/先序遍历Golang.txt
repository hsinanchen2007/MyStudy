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
func bstFromPreorder(preorder []int) *TreeNode {
    n := len(preorder)
	if n == 0{
		return nil
	}

	root := new(TreeNode)
	root.Val = preorder[0]

	for i := 1;i < len(preorder);i++{
        createbrach(root,preorder[i])
	}

    return root
}

func createbrach(root *TreeNode,leaf int){
    if leaf > root.Val && root.Right == nil{
		tmpRleaf := new(TreeNode)
		tmpRleaf.Val = leaf
		root.Right = tmpRleaf
		return
	}else if leaf > root.Val && root.Right != nil{
		createbrach(root.Right,leaf)
	}else if leaf < root.Val && root.Left == nil{
		tmpLleaf := new(TreeNode)
		tmpLleaf.Val = leaf
		root.Left = tmpLleaf
		return
	}else{
		createbrach(root.Left,leaf)
	}
}
```
只要确定好根节点，再根据先序遍历的定义，可以利用递归方式为每一个叶节点找合适的位置，遍历完所有叶节点，二叉树也就排好了。
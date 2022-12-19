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
	nums:=helpIncreasingBST(root)

	return buildTree(nums,0)
}

func buildTree(nums []int,i int) *TreeNode{
	var tree *TreeNode
	tree=new(TreeNode)
	tree.Val=nums[i]
	if i< len(nums)-1{
		tree.Right=buildTree(nums,i+1)
		tree.Left=nil
	}
	return tree
}

func helpIncreasingBST(root *TreeNode)[]int{
	if root==nil{
		return nil
	}
	left:=helpIncreasingBST(root.Left)
	right:=helpIncreasingBST(root.Right)
	return append(append(left,root.Val),right...)
}
```
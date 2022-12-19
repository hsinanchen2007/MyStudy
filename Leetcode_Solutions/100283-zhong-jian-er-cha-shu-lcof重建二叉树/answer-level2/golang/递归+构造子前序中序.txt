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
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0{
		return nil
	}
	root := new(TreeNode)
	root.Val = preorder[0]
	var index int
	for i := 0; i < len(inorder); i++ {
		if inorder[i] == root.Val {
			index = i
			break
		}
	}

	//fmt.Printf("pre1:%v,pre2:%v\n",preorder[1:index+1],preorder[index+1:])
	//fmt.Printf("i1:%v,i2:%v\n",inorder[:index],inorder[index+1:])

	root.Left = buildTree(preorder[1:index+1], inorder[:index])
	root.Right = buildTree(preorder[index+1:], inorder[index+1:])
	return root
}
```
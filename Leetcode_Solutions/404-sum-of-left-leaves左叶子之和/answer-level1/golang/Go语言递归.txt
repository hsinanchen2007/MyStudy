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
func sumOfLeftLeaves(root *TreeNode) int {
	var ans = 0
    if root == nil{
    	return 0
	}else{
		countTotal(root,&ans)
		return ans
	}
}
func countTotal(root *TreeNode,ans *int){
	if root != nil{//非空
		if root.Left != nil{//左非空
			if root.Left.Left == nil && root.Left.Right == nil {
				*ans = *ans + root.Left.Val
			}
			countTotal(root.Left,ans)
			countTotal(root.Right,ans)
		}
		if root.Left == nil && root.Right != nil{//左空，但右边非空
			countTotal(root.Right,ans)
		}
	}
}
```
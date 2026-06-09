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
func longestUnivaluePath(root *TreeNode) int {
	num:=0
	findLongestUnivaluePath(root,&num)
	return num
}

func findLongestUnivaluePath(root *TreeNode,num *int) int{
	if root==nil{
		return 0
	}
	l:=findLongestUnivaluePath(root.Left,num)
	r:=findLongestUnivaluePath(root.Right,num)
	var al,ar int
	if root.Left!=nil&&root.Left.Val==root.Val{
		al=l+1
	}
	if root.Right!=nil&&root.Right.Val==root.Val{
		ar=r+1
	}
	*num = int(math.Max(float64(*num), float64(ar+al)))
	return int(math.Max(float64(al), float64(ar)))
}
```


```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Info struct {
	isBalance bool
	height int
}

func isBalanced(root *TreeNode) bool {
	if root == nil{
        return true
    }
    return Process(root).isBalance
}

func Process(Node *TreeNode)Info{
	if Node == nil{
		return Info{true,0}
	}
	leftInfo := Process(Node.Left)
	rightInfo := Process(Node.Right)

	if !leftInfo.isBalance{
		return Info{false,0}
	}
	if !rightInfo.isBalance{
		return Info{false,0}
	}
	return Info{int(math.Abs(float64(leftInfo.height-rightInfo.height)))<2,int(math.Max(float64(leftInfo.height),float64(rightInfo.height)))+1}
}
```
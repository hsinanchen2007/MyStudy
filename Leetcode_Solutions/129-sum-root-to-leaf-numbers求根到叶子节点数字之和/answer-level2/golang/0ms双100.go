### 解题思路
此处撰写解题思路
深度优先搜索算法
刚开始用指针失败了后面发现用值类型就好了
每次往下遍历一层就需要把前面的*10
最关键的在于sum sum1是用根节点的值
if root.Left!=nil{
		sum=sum*10+root.Val
		left=sumNumbers1(root.Left,sum,sum)
	}
	if root.Right!=nil{
		sum1=sum1*10+root.Val
		right=sumNumbers1(root.Right,sum1,sum1)
	}
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
func sumNumbers(root *TreeNode) int {
	//ab分别用来记录左右的值
	a,b:=0,0
	return sumNumbers1(root,a,b)
}
func sumNumbers1(root *TreeNode,sum,sum1 int) int {
	left,right:=0,0
	if root==nil{
		return 0
	}else if root.Left==nil&&root.Right==nil{
		return sum*10+root.Val
	}
	if root.Left!=nil{
		sum=sum*10+root.Val
		left=sumNumbers1(root.Left,sum,sum)
	}
	if root.Right!=nil{
		sum1=sum1*10+root.Val
		right=sumNumbers1(root.Right,sum1,sum1)
	}
	return left+right
}
```
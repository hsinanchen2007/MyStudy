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
	root1Res:=make([]int,0)
	root2Res:=make([]int,0)
	helpleafSimilar(root1,&root1Res)
	helpleafSimilar(root2,&root2Res)
	if len(root1Res)!= len(root2Res){
		return false
	}
	for i:=0;i< len(root1Res);i++{
		if root1Res[i]!=root2Res[i]{
			return false
		}
	}
	return true
}

func helpleafSimilar(root *TreeNode,res *[]int){
	if root==nil{
		return 
	}
	if root.Left!=nil||root.Right!=nil{
		//先遍历左边
		helpleafSimilar(root.Left,res)
		//再遍历右边
		helpleafSimilar(root.Right,res)
	}else{
		*res= append(*res, root.Val)
	}
}
```
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
func binaryTreePaths(root *TreeNode) []string {
	var ans = make([]string,0)
	binaryTreeSubPaths(root,"",&ans)
	return ans
}

func binaryTreeSubPaths(temp *TreeNode,path string,ans *[]string){
	var temp0 = make([]string,0)
	if temp != nil{
		path = path + intToString(temp.Val)
		if temp.Left == nil && temp.Right == nil{
			*ans = append(*ans,path)
			temp0 = append(temp0,path)
			//fmt.Println(ans)
		}
			path = path + "->"
			binaryTreeSubPaths(temp.Left,path,ans)
			binaryTreeSubPaths(temp.Right,path,ans)

	}
}
func intToString(a int) string{
	return strconv.Itoa(a)
}
```
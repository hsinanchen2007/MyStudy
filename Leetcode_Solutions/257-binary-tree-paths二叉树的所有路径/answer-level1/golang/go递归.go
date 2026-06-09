### 解题思路
此处撰写解题思路
遍历第一排节点 1   []string{1}
遍历第二排节点2 3  []string{"1->2","1->3"}
遍历第二排节点5  []string{"1->2->5","1->3"}
每次遍历下面一排就是把下面的加入进数组中

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
	if root == nil {
		return nil
	}
	str:=strconv.Itoa(root.Val)
	var data []string
	if root.Left!=nil{
		strs:=binaryTreePaths(root.Left)
		for _, v := range strs {
			data=append(data,str+"->"+v)
		}
		//return
	}
	if root.Right!=nil{
		strs:=binaryTreePaths(root.Right)
		for _, v := range strs {
			data=append(data,str+"->"+v)
		}
	}
	if len(data)==0{
		return []string{str}
	}
	return data
}
```
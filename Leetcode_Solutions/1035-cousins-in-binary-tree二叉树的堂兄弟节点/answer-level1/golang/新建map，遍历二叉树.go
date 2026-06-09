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
//深度相同，父节点不同，值是唯一，考虑用map
func isCousins(root *TreeNode, x int, y int) bool {
	depth:=0
	fatherMap:=make(map[int]*TreeNode)
	depthMap:=make(map[int]int)
	helpIsCousins(root,nil,&fatherMap,&depthMap,depth)
	return  fatherMap[x]!=fatherMap[y]&&depthMap[x]==depthMap[y]
}

func helpIsCousins(root,father *TreeNode,fatherMap *map[int]*TreeNode,depthMap *map[int]int,depth int){
	if root==nil{
		return
	}
	(*fatherMap)[root.Val]=father
	(*depthMap)[root.Val]=depth
	helpIsCousins(root.Left,root,fatherMap,depthMap,depth+1)
	helpIsCousins(root.Right,root,fatherMap,depthMap,depth+1)

}
```
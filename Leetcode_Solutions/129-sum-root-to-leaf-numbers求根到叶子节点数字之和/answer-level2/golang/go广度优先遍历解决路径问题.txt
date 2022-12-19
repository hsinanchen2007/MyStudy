### 解题思路
直接上代码吧，语言表述能力不行，囧

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
	if root==nil{
		return 0
	}
	queue:=list.New()
	queue.PushBack(root)
	sum:=0
	for queue.Len()!=0{
		lenth:=queue.Len()
		for i:=0;i<lenth;i++{
			ele:=queue.Front()
			queue.Remove(ele)
			node:=ele.Value.(*TreeNode)
			val:=node.Val
			if node.Right==nil&&node.Left==nil{
				sum+=val
			}
			if node.Right!=nil{
				node.Right.Val+=val*10
				queue.PushBack(node.Right)
			}
			if node.Left!=nil{
				node.Left.Val+=val*10
				queue.PushBack(node.Left)
			}
		}
	}
	return sum
}
```
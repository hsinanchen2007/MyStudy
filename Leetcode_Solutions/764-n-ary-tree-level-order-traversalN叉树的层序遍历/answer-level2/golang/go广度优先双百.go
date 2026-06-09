就是普通二叉树层序遍历的改版，直接看代码吧

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
	var res [][]int
	var arr[]*Node
	if root!=nil{
		arr=append(arr,root)
		for len(arr)!=0{
			temp:=len(arr)
			var level []int
			for i:=0;i<temp;i++{
				level=append(level,arr[i].Val)
				for _,v:=range arr[i].Children{
					arr=append(arr,v)
				}
			}
            res=append(res,level)
			arr=arr[temp:]
		}
	}
	return res
}
```
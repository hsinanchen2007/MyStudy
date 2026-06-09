使用迭代法，使用golang里自带的链表list。
创建两个list，分别将节点，(sum-节点的值)放进去。
使用两个链表时间和空间的效率都低。
代码如下
```go []
import list2 "container/list"
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	list := list2.New()
	list3 := list2.New()
	list.PushFront(root)
	list3.PushFront(sum-root.Val)
	for list.Len() > 0 {
		currentLen := list.Len()

		for i:=0;i<currentLen ;i++  {
			node := list.Remove(list.Back()).(*TreeNode)
			currentSum := list3.Remove(list3.Back()).(int)
			if  node.Left == nil && node.Right == nil && currentSum == 0{
				return true
			}
			if node.Left != nil {
				list.PushFront(node.Left)
				list3.PushFront(currentSum-node.Left.Val)

			}
			if node.Right != nil {
				list.PushFront(node.Right)
				list3.PushFront(currentSum-node.Right.Val)

			}

		}
	}
	return false

}
```


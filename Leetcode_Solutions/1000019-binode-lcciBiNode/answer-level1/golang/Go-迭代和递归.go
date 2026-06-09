
方法1：
进行迭代
要求值的顺序不变，可利用BST的中序遍历有序的特性
在通常实现非递归的中序遍历时，都会使用stack来实现先进后出，但是go没有专门的stack，可以使用slice的代替。
定义一个新链表头，每次出栈都加入到当前链表头的右子树，并将当前链表头左子树置为nil，然后移动链表头

```
func convertBiNode(root *TreeNode) *TreeNode {
	newList := &TreeNode{}
	head := newList
	var stack []*TreeNode
	for root != nil || len(stack) != 0 {
		if root != nil {
			//入栈
			stack = append(stack, root)
			root = root.Left
		} else {
			//出栈
			pop := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			//将pop加入到单向链表
			pop.Left = nil
			newList.Right = pop
			newList = pop
			//继续遍历右子树
			root = pop.Right
		}
	}
	return head.Right
}
```


![image.png](https://pic.leetcode-cn.com/dd3d80b31368b3ee9261d666879e0f1ecbe0bed0ca2a8dba35ca679efa734d1b-image.png)

方法2：
使用递归
依然是中序遍历，将每次得到的节点放到新链表当前节点的Right。
注意：需要将当前新链表指针所在位置传入，并在更新后返回，以便在返回的上一个递归函数中，使用新的地址

```
func convertBiNode(root *TreeNode) *TreeNode {
	newTree := &TreeNode{}
	inOrder(root, newTree)
	return newTree.Right
}
func inOrder(root *TreeNode, pos *TreeNode) *TreeNode {
	if root == nil {
		return pos
	}
	pos = inOrder(root.Left, pos)
	pos.Right = root
	pos.Left = nil
	pos = root
	pos = inOrder(root.Right, pos)
	return pos
}
```

这种方法会超出时间限制：
![image.png](https://pic.leetcode-cn.com/038f3c28e965344f5d342a2c11bf1b80f62cadbfd910ea1778d78b5137e2bfe7-image.png)
